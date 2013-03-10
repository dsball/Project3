/*-------------------------------------driver.cpp
Daniel Ball
CSC 161 Lab 1

*/


#include "menu.h"
#include "utility.h"
#include "stack.h"
#include "queue.h"

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
	Queue queueList;

	menuA.addItem("Push Stack");
	menuA.addItem("Pop Stack");
	menuA.addItem("List Stack");
	menuA.addItem("Enqueue Queue");
	menuA.addItem("Dequeue Queue");
	menuA.addItem("List Queue");
	menuA.addItem("exit");
	
	while(choice != 7)
	{
		choice = menuA.getChoice();
		switch(choice)
		{
		case 1:
			cout<<"Adding to Stack...\n";
			stackList += stackList.makeNode();
			break;
		case 2:
			cout<<"Removing from Stack...\n";
			stackList.pop();
			break;
		case 3:
			cout<<"Listing stack...\n";
			cout<<stackList;
			pause();
			break;
		case 4:
			cout<<"Adding to queue ...\n";
			queueList +=queueList.makeNode();
			break;
		case 5:
			cout<<"Removing from queue...\n";
			queueList.dq();
			break;
		case 6:
			cout<<"Listing queue...\n";
			cout<<queueList;
			pause();
			break;
		case 7:
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