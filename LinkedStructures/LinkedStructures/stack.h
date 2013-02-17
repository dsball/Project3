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
		void push();
		void pop();
		void list();
		~Stack();
};




#endif