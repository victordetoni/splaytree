#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <bsd/sys/tree.h>
#include <sys/time.h>

#define   EXPIRED  3 #in seconds

struct list_el {
   SPLAY_ENTRY(list_el) entry;
   time_t idx;
   int val1;
   struct timeval tv;
};

pthread_t thread_1, thread_2;

int
intcmp(struct list_el *e1, struct list_el *e2)
{
   return (e1->idx < e2->idx ? -1 : e1->idx > e2->idx);
}

SPLAY_HEAD(inttree, list_el) head = SPLAY_INITIALIZER(&head);
SPLAY_PROTOTYPE(inttree, list_el, entry, intcmp);
SPLAY_GENERATE(inttree, list_el, entry, intcmp);

SPLAY_HEAD(inttree2, list_el) head2 = SPLAY_INITIALIZER(&head2);
SPLAY_PROTOTYPE(inttree2, list_el, entry, intcmp);
SPLAY_GENERATE(inttree2, list_el, entry, intcmp);

long double i = 0;
struct list_el *curr, *var;
struct timeval tv;

void *gettime() {
    for(;;) {
        gettimeofday(&tv,NULL);
        sleep(1);
    }
}

void *addNumber() {

   for(;;) {
         struct list_el find;
         curr = (struct list_el *)malloc(sizeof(struct list_el));
         curr->val1 = i+i;
         curr->tv.tv_sec = tv.tv_sec;
         curr->idx = i;
         SPLAY_INSERT(inttree, &head, curr);

         i++;
         var = SPLAY_MIN(inttree, &head);
            if((tv.tv_sec - var->tv.tv_sec) > EXPIRED) {
                SPLAY_REMOVE(inttree, &head, var);
                free(var);
            }
         var = SPLAY_MAX(inttree, &head);
   }
}

int main() {

        pthread_create(&thread_1,NULL,gettime,NULL);
        pthread_create(&thread_1,NULL,addNumber,NULL);

    for (;;) {
        printf("total: %Lf\n", i);
        sleep(1);
    }
}
