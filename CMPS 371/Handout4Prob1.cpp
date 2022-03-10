//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 4 Problem 1
// Due Date: Thursday 3/10/2022
// Purpose: This application finds the
// average of 10 random numbers less than
// 20.
//--------------------------------------

#include <iostream>
using namespace std;

int num, i, sum = 0, zero = 0, ten = 10, avg_int, avg_dec;

void generateRand()
{
	num = rand() % 20;
	cout << num << " ";
	sum += num;
}

void displayAvg()
{
	cout << endl;
	cout << "   Average: " << avg_int << "." << avg_dec << endl;
}

int main()
{
	srand(time(0));
	cout << "List of random numbers: ";

	_asm
	{
		mov	i, 1;
		forloop :
			call generateRand;
			inc i;
			cmp i, 10;
			je done;
			jmp forloop;
		done :
			mov eax, sum;
			cdq;
			idiv ten;
			mov avg_int, eax;
			mov avg_dec, edx;
			call displayAvg;
	}

	system("pause");
	return 0;
}