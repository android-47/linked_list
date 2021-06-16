#ifndef NODE_H
#define NODE_H

#include <iostream>    /* cin, cout, endl */
#include <cstdlib>     /* srand(), rand(), atoi() */
#include <ctime>       /* time() */
#include <cstring>     /* strlen(), strcmp(), strcpy() */ 


class Node {   
    private:
    public:
        int val; // the value that this node stores
        Node *next; // a pointer to the next node in the list
        Node(int value);
        Node();
}; 

#endif