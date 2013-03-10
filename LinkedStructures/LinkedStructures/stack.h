/*------------------------------------stack.h
Purpose: provides general utility functions, headers, and generic using declarations.

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
node			struct			data structure for making stack
num1            int             data member
num2            int             data member
num3            int             data member
next			node pointer    pointer to next node

head            node pointer    pointer to stack head
current         node pointer    pointer to current node
first           bool		    used to populate first node before generating new nodes


--- Functions ---
Name              Return    Description; Parameter description
--------------------------------------------------------------------------------------------
Stack()           none      default constructor, initializes stack   
makeNode()        node     creates and returns a single node with filled values
pop()             void      removes first node from the stack
list()            void      lists data for each node in the stack
~Stack()          none      successively deletes nodes before closing an instance of the class
operator+         Stack&    Adds a node to the linked structure, returns the address of the resulting linked structure
	params: Stack class - left operand, modified with node param
	        node struct - right operand, is appended to Stack class
operator+=        Stack&  creates a compound assignment for overloaded operator+.
    params: Stack class - class instance to be modified 
	        node struct - node to be appended to class.
operator<<        ostream&  overloads << operator to allow use on stack class, outputs linked structure data to calling stream
    params: ostream&    -  ostream being added to
	        Stack&      -  address of class containing linked structure data


*/

#ifndef _STACK_INTERFACE_
#define _STACK_INTERFACE_

#include "utility.h"

struct node
{
	int num1;
	int num2;
	int num3;
	node* next;
};

class Stack
{
	protected:
		node* head;
	public:
		Stack();
		node* makeNode();
		void pop();
		Stack& operator +(node*);
		Stack& operator +=(node*);
		friend ostream& operator<<(ostream& , const Stack&);
		~Stack();
};




#endif

//----------------------------------------------------------------------------------------------------------------------

