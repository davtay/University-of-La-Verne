//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 2 Problem 3
// Due Date: Thursday 2/24/2022
// Purpose: This program computes the
// average of 3 exam scores.
//--------------------------------------
#include <iostream>
using namespace std;

int exam1, exam2, exam3, avg, number = 3;

int main()
{
	cout << "Please enter your 3 exam scores: ";
	cin >> exam1 >> exam2 >> exam3;

	_asm
	{
		mov		eax, exam1;
		add		eax, exam2;
		add		eax, exam3;
		cdq;
		idiv		number;
		mov		avg, eax;
	}

	cout << "Your average score is " << avg << endl;
	system("pause");
	return 0;
}