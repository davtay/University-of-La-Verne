//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 4 Problem 2
// Due Date: Thursday 3/10/2022
// Purpose: This application a sentence
// and counts the number of uppercase
// letters and digits.
//--------------------------------------

#include <iostream>
using namespace std;

int count_upper, count_digit;
char c;

void enterSentence()
{
	cout << "Enter a sentence: ";
}

void readCharacter()
{
	cin.get(c);
}

int main() 
{
	_asm
	{
		call enterSentence;
		call readCharacter;
	whileLoop :
		cmp c, '\n';
		je done;
		cmp c, 'Z';
		jle maybeUpper;
		jmp readAgain;
	maybeUpper :
		cmp c, 'A';
		jge isUpper;
		jl maybeDigit;
	isUpper :
		inc count_upper;
		call readAgain;
	maybeDigit :
		cmp c, '9';
		jle isDigit;
		jg readAgain;
	isDigit :
		cmp c, '0';
		jl readAgain;
		inc count_digit;
		jmp readAgain;
	readAgain :
		call readCharacter;
		jmp whileLoop;
	done :
	}

	cout << "   Number of upper letters: " << count_upper << endl;
	cout << "   Number of digits: " << count_digit << endl;

	system("pause");
	return 0;
}