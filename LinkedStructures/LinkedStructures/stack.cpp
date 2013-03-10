#include "stack.h"


//default constructor, initializes stack  
Stack::Stack()
{
	head = nullptr;
}

//first instance: adds data to the head, all future: adds new node and data
Stack& Stack::operator+(node* tempNode)
{
	node* current = new node;
	current = tempNode;
	current->next = head;
	head = current;
	return *this;
}

//uses + operator overload to create += operator overload
Stack& Stack::operator+=(node* tempNode)
{
	*this = *this + tempNode;
	return *this;
}

//removes first node from the stack
void Stack::pop()
{
	node* current = head;
	head = head->next;
	cout<<"Deleting "<<current->num1<<endl;
	delete current;
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

//successively deletes nodes before closing an instance of the class
Stack::~Stack()
{
	cout<<"Freeing memory...";
	node* current;
	while(head)
	{
		current = head;
		head = head->next;
		cout<<"Deleting "<<current->num1<<endl;
		delete current;
	}
}

node* Stack::makeNode()
{
	node* tempNode = nullptr;
	tempNode = new node;
	if(!tempNode)
	{
		cout<<"Out of memory!";
		exit(0);
	}

	
	cout<<"Enter num1: ";
	while(!(cin>>tempNode->num1))
	{
		cin.clear();
		cin.sync();
		cout<<"Error inputting num1, try again: ";
	}
	cout<<"Enter num2: ";
	while(!(cin>>tempNode->num2))
	{
		cin.clear();
		cin.sync();
		cout<<"Error inputting num2, try again: ";
	}
	cout<<"Enter num3: ";
	while(!(cin>>tempNode->num3))
	{
		cin.clear();
		cin.sync();
		cout<<"Error inputting num3, try again: ";
	}
	tempNode->next = nullptr;
	return tempNode;
}
