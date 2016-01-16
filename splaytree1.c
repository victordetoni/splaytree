Last login: Fri Jan 15 23:12:39 on ttys000
Victors-MacBook-Pro:~ victordetoni$ ssh root@10.251.251.248 -v
OpenSSH_6.9p1, LibreSSL 2.1.8
debug1: Reading configuration data /etc/ssh/ssh_config
debug1: /etc/ssh/ssh_config line 21: Applying options for *
debug1: Connecting to 10.251.251.248 [10.251.251.248] port 22.
debug1: Connection established.
debug1: key_load_public: No such file or directory
debug1: identity file /Users/victordetoni/.ssh/id_rsa type -1
debug1: key_load_public: No such file or directory
debug1: identity file /Users/victordetoni/.ssh/id_rsa-cert type -1
debug1: identity file /Users/victordetoni/.ssh/id_dsa type 2
debug1: key_load_public: No such file or directory
debug1: identity file /Users/victordetoni/.ssh/id_dsa-cert type -1
debug1: key_load_public: No such file or directory
debug1: identity file /Users/victordetoni/.ssh/id_ecdsa type -1
debug1: key_load_public: No such file or directory
debug1: identity file /Users/victordetoni/.ssh/id_ecdsa-cert type -1
debug1: key_load_public: No such file or directory
debug1: identity file /Users/victordetoni/.ssh/id_ed25519 type -1
debug1: key_load_public: No such file or directory
debug1: identity file /Users/victordetoni/.ssh/id_ed25519-cert type -1
debug1: Enabling compatibility mode for protocol 2.0
debug1: Local version string SSH-2.0-OpenSSH_6.9
debug1: Remote protocol version 2.0, remote software version OpenSSH_6.6.1p1 Ubuntu-2ubuntu2
debug1: match: OpenSSH_6.6.1p1 Ubuntu-2ubuntu2 pat OpenSSH_6.6.1* compat 0x04000000
debug1: Authenticating to 10.251.251.248:22 as 'root'
debug1: SSH2_MSG_KEXINIT sent
debug1: SSH2_MSG_KEXINIT received
debug1: kex: server->client chacha20-poly1305@openssh.com <implicit> none
debug1: kex: client->server chacha20-poly1305@openssh.com <implicit> none
debug1: expecting SSH2_MSG_KEX_ECDH_REPLY
debug1: Server host key: ssh-rsa SHA256:VMzhBVApbX7h3nZkdAuhzpi6NMNjPNh2fhp2l1x7czE
debug1: Host '10.251.251.248' is known and matches the RSA host key.
debug1: Found key in /Users/victordetoni/.ssh/known_hosts:23
debug1: SSH2_MSG_NEWKEYS sent
debug1: expecting SSH2_MSG_NEWKEYS
debug1: SSH2_MSG_NEWKEYS received
debug1: Roaming not allowed by server
debug1: SSH2_MSG_SERVICE_REQUEST sent
debug1: SSH2_MSG_SERVICE_ACCEPT received
debug1: Authentications that can continue: publickey,password
debug1: Next authentication method: publickey
debug1: Trying private key: /Users/victordetoni/.ssh/id_rsa
debug1: Offering DSA public key: /Users/victordetoni/.ssh/id_dsa
debug1: Authentications that can continue: publickey,password
debug1: Trying private key: /Users/victordetoni/.ssh/id_ecdsa
debug1: Trying private key: /Users/victordetoni/.ssh/id_ed25519
debug1: Next authentication method: password
root@10.251.251.248's password: 
debug1: Authentication succeeded (password).
Authenticated to 10.251.251.248 ([10.251.251.248]:22).
debug1: channel 0: new [client-session]
debug1: Requesting no-more-sessions@openssh.com
debug1: Entering interactive session.
debug1: Sending environment.
debug1: Sending env LC_CTYPE = UTF-8
Welcome to Ubuntu 14.04.3 LTS (GNU/Linux 3.19.0-25-generic x86_64)

 * Documentation:  https://help.ubuntu.com/

  System information as of Sat Jan 16 18:44:22 BRST 2016

  System load:  1.76              Processes:           163
  Usage of /:   31.0% of 9.46GB   Users logged in:     0
  Memory usage: 36%               IP address for eth2: 10.251.251.248
  Swap usage:   0%

  Graph this data and manage this system at:
    https://landscape.canonical.com/

97 packages can be updated.
47 updates are security updates.

You have mail.
Last login: Sat Jan 16 00:30:09 2016 from 10.251.251.106
root@dev1:~# cat splay
splay1    splay1.c  splay2    splay2.c  splay3    splay3.c  splay4    splay4.c  splay5    splay5.c  
root@dev1:~# cat splay^C
root@dev1:~# l s-lart^C
root@dev1:~# ls -lart splay*
-rw-r--r-- 1 root root  3103 Dec 29 11:20 splay1.c
-rwxr-xr-x 1 root root 13671 Dec 29 11:20 splay1
-rw-r--r-- 1 root root  2486 Dec 29 11:23 splay2.c
-rwxr-xr-x 1 root root 13786 Dec 29 11:23 splay2
-rw-r--r-- 1 root root  2399 Dec 29 11:25 splay3.c
-rwxr-xr-x 1 root root 13761 Dec 29 11:25 splay3
-rw-r--r-- 1 root root  1900 Dec 29 11:42 splay4.c
-rwxr-xr-x 1 root root 13330 Dec 29 11:42 splay4
-rw-r--r-- 1 root root  2161 Dec 29 13:26 splay5.c
-rwxr-xr-x 1 root root 13649 Dec 29 13:26 splay5
root@dev1:~# ./splay5 
total: 0.000000
total: 5155398.000000
total: 10449363.000000
total: 15796594.000000
total: 20457739.000000
^C
root@dev1:~# 
root@dev1:~# 
root@dev1:~# vim splay5.c

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
