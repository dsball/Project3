#ifndef _STACK_INTERFACE_
#define _STACK_INTERFACE_

#include "utility.h"



struct node
{
	string name;
	string weapon;
	string armor;
	node* next;
};

class Stack
{
	private:
		nodeptr head;
		nodeptr tail;
		nodeptr current;
	public:
		Stack();
		Stack Push();
		Stack Pop();
		void List();
		~Stack();
};

typedef node* nodeptr;

#endif