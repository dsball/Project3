/*------------------------------------stack.h
Purpose: provides general utility functions, headers, and generic using declarations.

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
node			struct			data structure for making stack
num1            int             placeholder data member
num2            int             placeholder data member
num3            int             placeholder data member
next			node pointer    pointer to next node

head            node pointer    pointer to stack head
current         node pointer    pointer to current node
first           bool		    used to populate first node before generating new nodes


--- Functions ---
Name              Return    Description; Parameter description
--------------------------------------------------------------------------------------------
Stack()           none      default constructor, initializes stack   
push()            void      first instance: adds data to the head, all future: adds new node and data
pop()             void      removes first node from the stack
list()            void      lists data for each node in the stack
~Stack()          none      successively deletes nodes before closing an instance of the class

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
	private:
		node* head;
		node* current;
		bool first;
	public:
		Stack();
		void pop();
		//void push();
		Stack& operator +(node);
		Stack& operator +=(node);
		void list();
		friend ostream& operator<<(ostream& , const Stack&);
		~Stack();
};




#endif

//----------------------------------------------------------------------------------------------------------------------

