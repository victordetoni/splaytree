# splaytree examples
 splay tree is a self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again
 
 Example code in C that include new items in the memory and remove expired items.
 
 The main goal of this code is measure how many entries per second is included.
 
 To run:
 ----------
 
 FreeBSD:
 
 gcc -pthread splaytree1.c -o splaytree1
 
 Ubuntu:
 
 apt-get install libbsd-dev
 
 gcc -pthread splaytree1.c -o splaytree1
