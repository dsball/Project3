/*-------------------------------------driver.cpp
Daniel Ball
CSC 161 Lab 1

*/


#include "menu.h"
#include "utility.h"
#include "stack.h"
#include "uimanip.h"


static const WORD colors[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
	0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
	0x0D, 0x0E, 0x0F
};


int main()
{
	int a = 1;
	int b = 5;
	int i = 0;
	bool aup = true;
	bool bup = true;

	while(true)
	{
		
		if(i%10 == 0)
		{
			cSet(i);
			if(i == 15) i = 0;
		}


		cGotoxy(a,b);
		Sleep(50);
		cout<<"+";
		if(aup == true && a<=25)
		{
			if(a!=25)
			{
				a++;
			}
			else
			{
				aup = false;
				a--;
			}
		}
		else
		{
			if(a == 0)
			{
				aup = true;
				a++;
			}
			else
			{
				a--;
			}
		}
		if(bup == true && b<=20)
		{
			if(b!=20)
			{
				b++;
			}
			else
			{
				bup = false;
				b--;
			}
		}
		else
		{
			if(b == 0)
			{
				bup = true;
				b++;
			}
			else
			{
				b--;
			}
		}
		i++;
		
	}


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