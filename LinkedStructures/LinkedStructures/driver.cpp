/*-------------------------------------driver.cpp
Daniel Ball
CSC 161 Lab 1

*/

#include "menu.h"
#include "utility.h"
#include "stack.h"
//#include "uimanip.h"

int main()
{
	/*cGotoxy(5,5);
	cout<<"TESTING";
	Sleep(1000);
	cGotoxy(5,5);
	cout<<"WINNNING!";
	pause();*/


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
			//The lab says to do data entry in the push function; however, I had to change for the operator+ modification:
			//I did data input in the driver because of the operator+ overload ... I had to have something to add to the class. I could have loaded an empty node
			//and filled it in the class, but that would have been unnecessarily obfuscated code ... i.e. unless it was known
			//that it was being entered at that point, it would be difficult to see what was being added to the stack.
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