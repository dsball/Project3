#include "stack.h"

//default constructor, initializes stack  
Stack::Stack()
{
	head = new node;
	current = head;
	head->next = nullptr;
	first = true;
}

//first instance: adds data to the head, all future: adds new node and data



//void Stack::push()
Stack Stack::operator+(node tempNode)
{

	if(first == true)
	{
		current = head;
		first = false;
	}
	else
	{
		current = new node;
		current->next = head;
		head = current;
	}

	current = &tempNode;
}

//removes first node from the stack
void Stack::pop()

{
	current = head;
	head = current->next;
	delete current;
	cout<<"Node deleted.";
}

// lists data for each node in the stack
ostream& operator<<(ostream& stackOut, const Stack& stackIn)
{
	while(stackIn.current != nullptr)
	{
		stackOut<<setw(15)<<stackIn.current->num1<<setw(15)<<stackIn.current->num2<<setw(15)<<stackIn.current->num3<<endl;
		current = current->next;
	}
	return stackOut;
}

//successively deletes nodes before closing an instance of the class
Stack::~Stack()
{
	current = head;
	while(head!= nullptr)
	{
		pop();
	}
}

