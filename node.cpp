#include <iostream>    /* cin, cout, endl */
#include <cstdlib>     /* srand(), rand(), atoi() */
#include <ctime>       /* time() */
#include <cstring>     /* strlen(), strcmp(), strcpy() */ 

#include "node.h"


/****************************************************************************************
 ** Function: called when this object is created
 ** Description: initializes the private members
 ** Parameters: none
 ** Pre-Conditions: must create a Node object
 ** Post-Conditions: members must be initialized
****************************************************************************************/
Node::Node(){
    this->next = NULL;
}


/****************************************************************************************
 ** Function: called when this object is created using parameters
 ** Description: initializes the private members using the arguements passed in
 ** Parameters: integer value
 ** Pre-Conditions: must create a Node object
 ** Post-Conditions: members must be initialized
****************************************************************************************/
Node::Node(int value){
    this->val = value;
    this->next = NULL;
}