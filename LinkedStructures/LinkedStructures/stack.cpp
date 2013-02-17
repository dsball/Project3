#include "stack.h"


Stack::Stack()
{
	head = new node;
	current = head;
	head->next = nullptr;
	first = true;
}

void Stack::push()
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

	cout<<"Enter num1: ";
	while(!(cin>>current->num1))
	{
		cin.clear();
		cin.sync();
		cout<<"Error inputting num1, try again: ";
	}
	cout<<"Enter num2: ";
	while(!(cin>>current->num2))
	{
		cin.clear();
		cin.sync();
		cout<<"Error inputting num2, try again: ";
	}
	cout<<"Enter num3: ";
	while(!(cin>>current->num3))
	{
		cin.clear();
		cin.sync();
		cout<<"Error inputting num3, try again: ";
	}
}

void Stack::pop()
{
	current = head;
	head = current->next;
	delete current;
	cout<<"Node deleted.";
}

void Stack::list()
{
	current = head;
	while(current != nullptr)
	{
		cout<<setw(15)<<current->num1<<setw(15)<<current->num2<<setw(15)<<current->num3<<endl;
		current = current->next;
	}
	pause();
}

Stack::~Stack()
{
	current = head;
	while(head!= nullptr)
	{
		pop();
	}
}
