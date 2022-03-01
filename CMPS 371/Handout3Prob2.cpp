//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 3 Problem 2
// Due Date: Thursday 1/3/2022
// Purpose: This application computes
// the membership cost.
//--------------------------------------
#include <iostream>
using namespace std;

string last_name;
int age;
char gender;

void showMaleTeen() {
	cout << "Hello Mr " << last_name << ", your membership is $40" << endl;
}

void showFemaleTeen() {
	cout << "Hello Ms " << last_name << ", your membership is $45" << endl;
}

void showMaleAdult() {
	cout << "Hello Mr " << last_name << ", your membership is $50" << endl;
}

void showFemaleAdult() {
	cout << "Hello Mrs " << last_name << ", your membership is $35" << endl;
}

int main()
{
	cout << "----------LA Fitness Club----------" << endl;
	cout << "Teenagers" << endl;
	cout << "   Male.........................$40" << endl;
	cout << "   Female.......................$45" << endl;
	cout << "Adults" << endl;
	cout << "   Male.........................$50" << endl;
	cout << "   Female.......................$35" << endl;

	cout << "Enter your last name: "; cin >> last_name;
	cout << "How old are you? "; cin >> age;
	cout << "What is your gender (m/f)? "; cin >> gender;

	_asm
	{
		cmp			age, 18;
		jle			notAdult;
		jg			adult;
	notAdult :
		cmp			gender, 'm';
		jne			femaleNotAdult;
		call		showMaleTeen;
		jmp			done;
	adult :
		cmp			gender, 'm';
		jne			femaleAdult;
		call		showMaleAdult;
		jmp			done;
	femaleNotAdult :
		call		showFemaleTeen;
		jmp			done;
	femaleAdult :
		call		showFemaleAdult;
		jmp			done;
	done :
	}

	system("pause");
	return 0;
}