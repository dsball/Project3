/*-------------------------------------driver.cpp
Daniel Ball
CSC 161 Lab 1

*/

#include "menu.h"
#include "utility.h"
#include "stack.h"

int main()
{
	Menu menuA;
	int choice = 0;
	Stack tempStack;
	node tempNode;

	if(!printFile("about.txt"))
	{
		cout<<"ERROR READING WELCOME FILE\n";
	}
	pause();

	Stack stackList;

	menuA.addItem("Push");
	menuA.addItem("Pop");
	menuA.addItem("List");
	menuA.addItem("exit");
	
	while(choice != 4)
	{
		choice = menuA.getChoice();
		switch(choice)
		{
		case 1:
			cout<<"Enter num1: ";
			while(!(cin>>tempNode.num1))
			{
				cin.clear();
				cin.sync();
				cout<<"Error inputting num1, try again: ";
			}
			cout<<"Enter num2: ";
			while(!(cin>>tempNode.num2))
			{
				cin.clear();
				cin.sync();
				cout<<"Error inputting num2, try again: ";
			}
			cout<<"Enter num3: ";
			while(!(cin>>tempNode.num3))
			{
				cin.clear();
				cin.sync();
				cout<<"Error inputting num3, try again: ";
			}
			tempNode.next = nullptr;
			stackList += tempNode;
			break;
		case 2:
			stackList.pop();
			break;
		case 3:
			cout<<stackList;
			pause();
			break;
		case 4:
			break;
		default:
			cout<<"invalid entry.\n";
			break;
		}
	}


	if(!printFile("goodbye.txt"))
	{
		cout<<"ERROR READING EXIT FILE\n";
	}
	pause();
	
	return 0;
}