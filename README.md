# splaytree example
 splay tree is a self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again. About: https://en.wikipedia.org/wiki/Splay_tree
 
 Example code in C that include new items in the memory and remove expired items.
 
 The main goal of this code is to measure how many entries per second is included and doesn't fill the available memory (memory recommended: 4GB RAM)
 
Compile and run
-----------

#### FreeBSD 10.x

    clang -pthread splaytree1.c -o splaytree1
    ./splaytree1
 
#### Ubuntu
 
    apt-get install libbsd-dev
    gcc -pthread splaytree1.c -o splaytree1
    ./splaytree1
