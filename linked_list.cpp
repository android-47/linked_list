#include <iostream>    /* cin, cout, endl */
#include <cstdlib>     /* srand(), rand(), atoi() */
#include <ctime>       /* time() */
#include <cstring>     /* strlen(), strcmp(), strcpy() */ 

#include "linked_list.h"
#include "node.h"


/****************************************************************************************
 ** Function: called when this object is created
 ** Description: initializes the private members
 ** Parameters: none
 ** Pre-Conditions: must create a lemur object
 ** Post-Conditions: members must be initialized
****************************************************************************************/
Linked_List::Linked_List(){
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
    this->prime_count = 0;
    this->prime_string = "";
}


/**********************************************************
 ** Function: deconstructor clears LinkedList
 ** Description: called when the program terminates, or this object is destroyed ** Parameters: none
 ** Pre-Conditions: user must quit application
 ** Post-Conditions: clears LinkedList and frees all allocated memory
**********************************************************/
Linked_List::~Linked_List(){
    clear();
}


/********************************************************** 
 ** Function: gets the length of LinkedList
 ** Description: called whenever the user wants the LinkedList length
 ** Parameters: none
 ** Pre-Conditions: length must be initialized 
 ** Post-Conditions: returns this -> length
**********************************************************/
int Linked_List::get_length(){
    return this->length;
}


/********************************************************** 
 ** Function: prints LinkedList
 ** Description: called whenever the user wants to print the LinkedList 
 ** Parameters: none
 ** Pre-Conditions: user must decide to print list
 ** Post-Conditions: LinkedList must print to screen 
**********************************************************/
void Linked_List::print(){
    // error handle? if length == 0;
    std::cout << "Your linked list is: ";
    Node *temp = head;
    while (temp != NULL){
        if (temp != head)
            std::cout << ", ";
        std::cout << temp->val;
        temp = temp->next; // temp node now becomes the next node
    }
    std::cout << std::endl;
}


/********************************************************** 
 ** Function: clears LinkedList
 ** Description: called whenever the user wants to clear the LinkedList
 and/or when the program terminates
 ** Parameters: none
 ** Pre-Conditions: user must decide to clear list / start again
 ** Post-Conditions: clears LinkedList and frees all allocated memory
**********************************************************/
void Linked_List::clear(){
    Node *temp = this->head;
    while (temp != NULL){
        // head becomes the next node because we delete the head in the next line
        this->head = temp->next; 
        delete temp;
        temp = this->head;
    }
    this->head = NULL;
    this->length = 0;
}


/**********************************************************
 ** Function: inserts value at the front of the linklist
 ** Description: called whenever the user adds an element to the front of the list 
 ** Parameters: integer value
 ** Pre-Conditions: must know what value to add
 ** Post-Conditions: returns the updated length
**********************************************************/
unsigned int Linked_List::push_front(int value){
    Node *newNode = new Node(value);
    if (this->head == NULL){
        this->head = newNode;
        this->tail = newNode;
    } else {
        // place newNode in the front by assigning newNode's next to the current head
        newNode->next = this->head; 
    }

    this->head = newNode; // assign head to the newNode
    this->length++;
    return this->length;
}


/**********************************************************
 ** Function: inserts value at the back of the linklist
 ** Description: called whenever the user adds an element to the back of the list 
 ** Parameters: integer value
 ** Pre-Conditions: must know what value to add
 ** Post-Conditions: returns the updated length
**********************************************************/
unsigned int Linked_List::push_back(int value){
    Node *newNode = new Node(value);
    if (this->head == NULL) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        // former node tail's next now points to newNode
        this->tail->next = newNode; 
        // tail gets assigned to the newNode (last node), including it's next NULL pointer
        this->tail = this->tail->next; 
    }
    this->length++;
    return this->length;
}


/**********************************************************
 ** Function: inserts value at specific index of LinkedList
 ** Description: called whenever the user adds an element in the middle of the list 
 ** Parameters: integer value, unsigned integer index
 ** Pre-Conditions: must know what value to add and where
 ** Post-Conditions: returns the updated length
**********************************************************/
unsigned int Linked_List::insert(int val, unsigned int index){
    // error handle?
    if (index == 0){
        push_front(val);
    } else if (index == this->length-1) {
        push_back(val);
    } else {
        Node *newNode = new Node(val);
        Node *current = this->head;

        unsigned int i = 1;
        while (current != NULL && i != index) {
            current = current->next;
            i++;
        }

        newNode->next = current->next;
        current->next = newNode;
        length++;
    }
    return this->length;
}



/**********************************************************
 ** Function: runs the application, acts as the main
 ** Description: called at the start of the program
 ** Parameters: none
 ** Pre-Conditions: must compile
 ** Post-Conditions: user decides to quit
**********************************************************/
void Linked_List::run_application(){
    int value = 0, index = 0;
    char sort = 'a', again = 'a';
    do {
		prompt_values(value);
		std::cout << std::endl;
		std::cout << "Sort ascending or descending (a or d)? "; std::cin >> sort;
		(sort == 'a') ? sort_ascending() : sort_descending();
		print();
		std::cout << "You have " << count_prime() <<  " prime number(s) in your list: " << prime_string << std::endl;
		std::cout << "Your list length is " << get_length() << std::endl << std::endl;

		std::cout << "Please enter a value to insert: "; std::cin >> value;
		std::cout << "Please enter an index to insert at (0-" << get_length() << "): "; std::cin >> index;
		insert(value, index);
		print();
		std::cout << "Your new list length is " << get_length() << std::endl << std::endl;
		std::cout << "Do you want to do this again (y or n)? "; std::cin >> again;
		clear();
	} while (again == 'y');
}


/**********************************************************
 ** Function: adds nodes to linked list
 ** Description: called at the start of the application
 ** Parameters: integer value
 ** Pre-Conditions: application must be runnning
 ** Post-Conditions: user decides to quit
**********************************************************/
void Linked_List::prompt_values(int value){
	char add_another = 'a';
	std::cout << "Please enter a number: "; std::cin >> value;
	push_back(value);
	do {
		std::cout << "Do you want another num (y or n): "; std::cin >> add_another;
		if (add_another == 'y'){
			std::cout << "Enter a number: "; std::cin >> value;
			push_back(value);
		} else
			break;
	} while (true);
}



/**********************************************************
 ** Function: displays prime_string neatly
 ** Description: called whenever the user prints the prime count
 ** Parameters: none
 ** Pre-Conditions: user must print prime count
 ** Post-Conditions: prime_string is printed
**********************************************************/
std::string Linked_List::get_primeString(){
    return this->prime_string;
}


/**********************************************************
 ** Function: counts the number of primes
 ** Description: called whenever the user wants to know the prime count
 ** Parameters: none
 ** Pre-Conditions: must be elements in linked list
 ** Post-Conditions: prime_count is updated
**********************************************************/
int Linked_List::count_prime(){
    Node *temp = this->head;
    this->prime_count = 0;
    this->prime_string = "";
    while (temp != NULL) {
        int n = temp->val;
        bool is_prime = true;
        if (n != 0 && n != 1) {
            for (int i = 2; i < n; i++){
                if (n % i == 0){
                    is_prime = false;
                    break;
                }
            }
            if (is_prime == true){
                this->prime_count++;
                if (prime_count > 1)
                    prime_string += ", ";
                prime_string += std::to_string(n);
            }
        }
        temp = temp->next;
    }
    return this->prime_count;
}




/********************************************************** 
 ** Function: acts as the main for sorting in ascending order
 ** Description: sorts LinkedList
 ** Parameters: none
 ** Pre-Conditions: the head must contain at least 1 value
 ** Post-Conditions: updates this -> head 
**********************************************************/
void Linked_List::sort_ascending(){
	for (unsigned int i = 0; i < this->length; i++){
		Node *previous = NULL;
		Node *current = head;   
		while (current->next != NULL){
			if (current->val > current->next->val){
				Node *temp = current->next;
				// if dealing with first node
				if (previous == NULL){
					current->next = temp->next;
					temp->next = current;
					previous = temp;
					head = previous;
				} else {
					previous->next = temp;
					current->next = temp->next;
					temp->next = current;
					previous = temp;
				}
			} else {
				previous = current;
				current = current->next;
			}
		}
	}
}

/********************************************************** 
 ** Function: acts as the main for sorting in descending order
 ** Description: sorts LinkedList
 ** Parameters: none
 ** Pre-Conditions: the head must contain at least 1 value
 ** Post-Conditions: updates this -> head 
**********************************************************/
void Linked_List::sort_descending(){
	for (unsigned int i = 0; i < this->length; i++){
		Node *previous = NULL;
		Node *current = head;   
		while (current->next != NULL){
			if (current->val < current->next->val){
				Node *temp = current->next;
				// if dealing with first node
				if (previous == NULL){
					current->next = temp->next;
					temp->next = current;
					previous = temp;
					head = previous;
				} else {
					previous->next = temp;
					current->next = temp->next;
					temp->next = current;
					previous = temp;
				}
			} else {
				previous = current;
				current = current->next;
			}
		}
	}
}



/********************************************************** 
 ** Function: sorts values ascending via merge sort
 ** Description: called whenever the user decides to sort ascending
 ** Parameters: Node address head
 ** Pre-Conditions: must know where the head of the head is
 ** Post-Conditions: returns a sorted LinkedList 
**********************************************************/
/*
Node Linked_List::merge_sort(Node &x_head){
    if (x_head == NULL || x_head->next == NULL)
        return x_head;

    Node start = x_head;
    Node middle = get_midNode(&start);
    Node end = middle->next;
    middle->next = NULL;

    left = merge_sort(start);
    right = merge_sort(end);

    return merge(left, right);
}
*/


/********************************************************** 
 ** Function: merges two LinkedLists
 ** Description: called whenever merge_sort is used
 ** Parameters: node address left, node address right
 ** Pre-Conditions: user must sort ascending
 ** Post-Conditions: returns left and right nodes merged 
**********************************************************/
/*
Node Linked_List::merge(Node &left, Node &right){
   Node temp = new Node;
   Node temp2 = temp;
   while (left != NULL && right != NULL) {
       temp2 = temp2->next;
       if (left->val <= right->val){
           temp2->next = left;
           left = left->next;
       } else {
           temp2->next = right;
           right = right->next
       }
   }
    if (left == NULL)
        return right;
    else
        return left;
}
*/

/********************************************************** 
 ** Function: find middle node
 ** Description: called whenever the user decides to sort ascending
 ** Parameters: Node address head
 ** Pre-Conditions: must know where the head of the head is
 ** Post-Conditions: returns the middle node
**********************************************************/
/*
Node Linked_List::get_midNode(Node &x_head){
    if (x_head == NULL)
        return x_head;

    Node temp1 = x_head;
    int count = 0;

    while (temp1 != NULL){
        temp1 = temp1->next;
        count++;
    }

    Node temp2 = x_head;
    for (int i = 0; i < count; i++)
        temp2 = temp2->next;

    return temp2;
}
*/