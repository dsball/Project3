#include "queue.h"

Queue::Queue()
{
	tail = nullptr;
}

void Queue::nq(node* tempNode)
{
	if(first)
	{
		head = tempNode;
		tail = head;
		first = false;
	}
	else
	{
		tail->next = tempNode;
		tail = tail->next;
	}
}

Queue& Queue::operator+(node* tempNode)
{
	if(first)
	{
		head = tempNode;
		tail = head;
		first = false;
	}
	else
	{
		tail->next = tempNode;
		tail = tail->next;
	}
	return *this;
}

//uses + operator overload to create += operator overload
Queue& Queue::operator+=(node* tempNode)
{
	*this = *this + tempNode;
	return *this;
}

void Queue::dq()
{
	pop();
	if(!head)
	{
		tail = nullptr;
		first = true;
	}
}

Queue::~Queue()
{

}