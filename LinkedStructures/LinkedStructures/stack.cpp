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
Stack& Stack::operator+(node tempNode)
{
	if(first == true)
	{
		head->num1 = tempNode.num1;
		head->num2 = tempNode.num2;
		head->num3 = tempNode.num3;
		first = false;
	}
	else
	{
		current = new node;
		current->num1 = tempNode.num1;
		current->num2 = tempNode.num2;
		current->num3 = tempNode.num3;
		current->next = head;
		head = current;
	}
	return *this;
}

//uses + operator overload to create += operator overload
Stack& Stack::operator+=(node tempNode)
{
	*this = *this + tempNode;
	return *this;
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
	node* currNode = stackIn.head;

	while(currNode != nullptr)
	{
		stackOut<<setw(15)<<currNode->num1<<setw(15)<<currNode->num2<<setw(15)<<currNode->num3<<endl;
		currNode = currNode->next;
	}
	return stackOut;
}

void Stack::list()
{
	current = head;
	while(current != nullptr)
	{
		cout<<setw(15)<<current->num1<<setw(15)<<current->num2<<setw(15)<<current->num3<<endl;
		current = current->next;
	}
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

