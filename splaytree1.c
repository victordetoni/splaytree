#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <bsd/sys/tree.h>
#include <sys/time.h>

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
/*
    if(e1->idx != -9280)
        return (e1->idx < e2->idx ? -1 : e1->idx > e2->idx);
        else if (e1->val1 != 32767)
            return (e1->val1 < e2->val1 ? -1 : e1->val1 > e2->val1);
     
//  return (e1->tv.tv_sec < e2->tv.tv_sec ? -1 : e1->tv.tv_sec > e2->tv.tv_sec);*/
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

    /*  
 
        */
//        find.val1 = curr->val1;

 //       if(SPLAY_FIND(inttree,&head,&find))
   //         printf("found %d\n", curr->val1);
        i++;
        //SPLAY_FOREACH(var, inttree, &head) {
        var = SPLAY_MIN(inttree, &head);
            if((tv.tv_sec - var->tv.tv_sec) > 3) {
                SPLAY_REMOVE(inttree, &head, var);
                free(var);
            }
        var = SPLAY_MAX(inttree, &head);
            //break;
        //  printf("%ld %ld %d\n",var->idx, var->tv.tv_sec, var->val1);
        //}*/
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
