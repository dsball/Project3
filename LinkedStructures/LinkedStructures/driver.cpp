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
			stackList.push();
			break;
		case 2:
			stackList.pop();
			break;
		case 3:
			stackList.list();
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