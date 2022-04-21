//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 5 Problem 3
// Due Date: Thursday 3/24/2022
// Purpose: This application computes information
// about the computer from a binary number
//--------------------------------------
#include <iostream>
using namespace std;

short c, e, f = 1;

void displayRegister() {
	cout << "ax = 0110 1001 0010 0011" << endl;
	cout << "Lights are on at floors:";
}

void displayFloor() {
	cout << " " << f;
}

void displayOn() {
	cout << "Floor 5 is already on, no change taken" << endl;
}

void displayOff() {
	cout << "Floor 5 was off. Turning on." << endl;
	cout << "ax = 0110 1001 0011 0011" << endl;
}

int main()
{

	_asm
	{
				call displayRegister
				mov ax, 0110100100100011b
				mov cx, 16
				mov c, 1
				mov bx, 1
		doLoop :
				cmp cx, 0
				je done
				and c, ax
				cmp c, 1
				je lightOn
				jne cont
		lightOn :
				mov f, bx
				call displayFloor
				jmp cont
		cont :
				mov c, 1
				dec cx
				shr ax, 1
				inc bx
				jmp doLoop
		done :
	}

	cout << endl;

	_asm
	{
				mov ax, 0110100100100011b
				mov e, 0x0010
				and e, ax
				cmp e, 0
				je off
		on :
				call displayOn
				jmp done5
		off :
				call displayOff
				jmp done5
		done5 :
	}

	system("pause");
	return 0;
}