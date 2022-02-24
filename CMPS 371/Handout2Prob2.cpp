//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 2 Problem 2
// Due Date: Thursday 2/24/2022
//--------------------------------------
#include <iostream>
using namespace std;

short drinks, sandwiches, total, drink_cost = 2, sw_cost = 5;

int main()
{
	cout << "----------MENU----------" << endl;
	cout << "Drinks________________$2" << endl;
	cout << "Sandwiches____________$5" << endl;
	cout << "How many drinks?";
	cin >> drinks;
	cout << "How many sandwiches?";
	cin >> sandwiches;

	_asm
	{
		mov		ax, drink_cost;
		imul	drinks;
		mov		bx, ax;
		mov		ax, sw_cost;
		imul	sandwiches;
		add		ax, bx;
		mov		total, ax;
	}

	cout << "Your total bill = " << total << endl;
	system("pause");
	return 0;
}