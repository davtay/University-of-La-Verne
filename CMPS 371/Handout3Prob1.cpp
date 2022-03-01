//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 3 Problem 1
// Due Date: Thursday 1/3/2022
// Purpose: This application computes
// the total bill of inputed menu items.
//--------------------------------------
#include <iostream>
using namespace std;

int total_drinks, cost_drinks, total_sandwiches, size_sandwich, total_bill, water_cost = 1, soda_cost = 2, beer_cost = 3, six_sandwich = 4, twelve_sandwich = 6;
char type_drink;

int main()
{
	cout << "----------MENU----------" << endl;
	cout << "Drinks" << endl;
	cout << "   Soda...............$2" << endl;
	cout << "   Water..............$1" << endl;
	cout << "   Beer...............$3" << endl;
	cout << "Sandwiches" << endl;
	cout << "   6 inches...........$4" << endl;
	cout << "   12 inches..........$6" << endl;
	cout << "How many drinks? "; cin >> total_drinks;
	cout << "   What kind of drink? (s/w/b) "; cin >> type_drink;
	cout << "How many sandwiches? "; cin >> total_sandwiches;
	cout << "   What size? (6/12) "; cin >> size_sandwich;

	_asm
	{
		mov			eax, total_drinks;
		cmp			type_drink, 'w';
		je			water;
		jl			notWater;
	water :
		imul		water_cost;
		jmp			notTwelve;
	notWater :
		cmp		type_drink, 's';
		jne			beer;
		imul		soda_cost;
		jmp			notTwelve;
	beer :
		imul		beer_cost;
		jmp			notTwelve;
	notTwelve :
		cmp			size_sandwich, 12;
		je			twelve_inch;
		mov			ebx, total_sandwiches;
		imul		ebx, six_sandwich;
		add			eax, ebx;
		mov			total_bill, eax;
		jmp			done;
	twelve_inch :
		mov			ebx, total_sandwiches;
		imul		ebx, twelve_sandwich;
		add			eax, ebx;
		mov			total_bill, eax;
		jmp			done;
	done :
	}

	cout << "      Your total bill is " << total_bill << endl;

	system("pause");
	return 0;
}