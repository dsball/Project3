#ifndef QUEUE_INTFC
#define QUEUE_INTFC

#include "stack.h"

class Queue:public Stack
{
	private:
		node* tail;
		bool first;
	public:
		Queue();
		void nq(node*);
		Queue& operator +(node*);
		Queue& operator +=(node*);
		void dq();
		~Queue();
};

#endif