//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 6 Problem 1
// Due Date: Thursday 4/7/2022
// Purpose: This application adds 6 random
// numbers to an array, displays the array,
// displays the total, min, and max.
//--------------------------------------

#include <iostream>
using namespace std;

int num, mx, mn, total, a[6], i;

void generateRand()
{
	num = rand() % 20;
}

void storeData()
{
	_asm
	{
			lea esi, a
			mov i, 0
		loop1:
			cmp i, 6
			je doneLoop1
			call generateRand
			mov ebx, num
			mov [esi], ebx
			add esi, 4
			inc i
			jmp loop1
		doneLoop1:
	}
}

void displayArray()
{
	cout << "The array is: ";
	for (int j = 0; j < i; ++j)
		cout << a[j] << " ";
	cout << endl;
}

void displayTotal()
{
	_asm
	{
			mov ebx, 0
			mov i, 0
			lea esi, a
		loop1:
			cmp i, 6
			je endLoop
			add ebx, [esi]
			inc i
			add esi, 4
			jmp loop1
		endLoop:
			mov total, ebx
	}
	cout << "The total is: " << total << endl;
}

void displayMin()
{
	_asm
	{
			lea esi, a
			mov ecx, [esi]
			mov i, 1
		cmpLoop:
			cmp i, 6
			je done
			add esi, 4
			cmp[esi], ecx
			jl newMin
		cont :
			inc i
			jmp cmpLoop
		newMin :
			mov ecx, [esi]
			jmp cont
		done :
			mov mn, ecx
	}
	cout << "The minimum is: " << mn << endl;
}

void displayMax()
{
	_asm
	{
			lea esi, a
			mov ecx, [esi]
			mov i, 1
		cmpLoop:
			cmp i, 6
			je done
			add esi, 4
			cmp [esi], ecx
			jg newMax
		cont:
			inc i
			jmp cmpLoop
		newMax:
			mov ecx, [esi]
			jmp cont
		done:
			mov mx, ecx
	}
	cout << "The maximum is: " << mx << endl;
}

int main()
{
	//srand has to go here otherwise no randomness
	srand(time(NULL));
	storeData();
	displayArray();
	displayTotal();
	displayMin();
	displayMax();

	system("pause");
	return 0;
}