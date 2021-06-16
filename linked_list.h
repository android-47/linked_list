#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>    /* cin, cout, endl */
#include <cstdlib>     /* srand(), rand(), atoi() */
#include <ctime>       /* time() */
#include <cstring>     /* strlen(), strcmp(), strcpy() */ 

#include "node.h"


class Linked_List {
    private:
        unsigned int length; // the number of nodes contained in the list
        Node *head; // a pointer to the first node in the list
        Node *tail; // a pointer to the last node in the list
        int prime_count;
        std::string prime_string;
    public:
        int get_length();
        void print(); // output a list of all integers contained within the list
        void clear(); // delete the entire list (remove all nodes and reset length to 0)
        unsigned int push_front(int); // insert a new value at the front of the list (returns the new length of the list)
        unsigned int push_back(int); // insert a new value at the back of the list (returns the new length of the list)
        unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
        void sort_ascending(); // sort the nodes in ascending order (recursive Merge Sort algorithm)
        void sort_descending(); // sort the nodes in descending order

        int count_prime();

        Linked_List();
        ~Linked_List();

		void run_application();
		void prompt_values(int);

        //void merge_sort(Node);
        //Node merge(Node, Node);
        //Node get_midNode(Node);

        std::string get_primeString();

};

#endif