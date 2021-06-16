/**********************************************************
 ** Author: Javier Garcia Ramirez
 ** Program: linked_list_imp
 ** Date Created: Tue. May 25, 2021
 ** Due Date: Sun. June 5, 2021
 ** Description: implemeted Linked List from C++ Standard Template Library
 ** Time Spent: ~11h 42m
 ** Input: binary decisions (y/n) and signed integers
 ** Output: the member functions implementation
**********************************************************/

#include <iostream>
#include <string>
#include <ctime>    // included to allow time() to be used
#include <cstdlib>  // include to allow rand() and srand() to be use

#include "linked_list.h" // include to allow rand() and srand() to be use
#include "node.h"


/**********************************************************
 ** Function: necessary for the program to run
 ** Description: used once and is active during the entire program
 ** Parameters: none
 ** Pre-Conditions: program must compile and must have included .h files
 ** Post-Conditions: must return 0 to indicate no errors
**********************************************************/
int main() {
    Linked_List linked_list;
	linked_list.run_application();
    return 0;
}