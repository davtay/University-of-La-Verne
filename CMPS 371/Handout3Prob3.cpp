//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 3 Problem 3
// Due Date: Thursday 1/3/2022
// Purpose: This application determines
// if the total of the pin is even or
// not even.
//--------------------------------------
#include <iostream>
using namespace std;

string name;
int pin, number, hundred = 100, ten = 10, two = 2, zero = 0, hundreds, tens;

void isEven() {
	cout << "   " << name << ", yes you can use " << pin << " as your bank pin number." << endl;
}

void isNotEven() {
	cout << "   " << name << ", no you cannot use " << pin << " as your bank pin number." << endl;
}

int main()
{
	
	cout << "Please enter your name: "; cin >> name;
	cout << name << ", please enter the first 3 digits of your SS: "; cin >> pin;

	_asm
	{
		mov			eax, pin;
		cdq;
		idiv		hundred;
		mov			ebx, eax;
		mov			eax, edx;
		cdq;
		idiv		ten;
		mov			hundreds, ebx;
		mov			tens, eax;
		add			edx, hundreds;
		add			edx, tens;
		mov			eax, edx;
		cdq;
		idiv		two;
		cmp			edx, zero;
		jne			isNotEven;
		call		isEven;
		jmp			done;
	isNotEven :
		call		isNotEven;
		jmp			done;
	done :
	}

	system("pause");
	return 0;

}