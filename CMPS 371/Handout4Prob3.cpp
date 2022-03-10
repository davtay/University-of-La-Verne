//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 4 Problem 3
// Due Date: Thursday 3/10/2022
// Purpose: This application generates
// 2 random numbers and tests the users
// addition of those numbers.
//--------------------------------------

#include <iostream>
using namespace std;

int num1, num2, guess, correct_guesses, wrong_guesses;
char answer;

void generateRand()
{
	srand(time(0));
	num1 = rand() % 20;
	num2 = rand() % 20;
}
void display()
{
	cout << num1 << " + " << num2 << " = ? ";
	cin >> guess;
}
void correct()
{
	cout << "   CORRECT" << endl;
}
void wrong()
{
	cout << "   WRONG" << endl;
}
void cont()
{
	cout << "Continue(y/n)? ";
	cin >> answer;
	cout << endl;
}
void finish()
{
	cout << "Number of CORRECT answers: " << correct_guesses << endl;
	cout << "Number of WRONG answers: " << wrong_guesses << endl;
}
int main()
{
	_asm
	{
	doLoop :
		call generateRand
		call display
		mov eax, num1
		add eax, num2
		cmp eax, guess
		je correctGuess
		jne wrongGuess
	correctGuess :
		inc correct_guesses
		call correct
		call cont
		cmp answer, 'y'
		je doLoop
		jne done
	wrongGuess :
		inc wrong_guesses
		call wrong
		call cont
		cmp answer, 'y'
		je doLoop
		jne done
	done :
		call finish
	}

	system("pause");
	return 0;
}