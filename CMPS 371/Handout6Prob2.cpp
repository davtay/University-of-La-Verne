//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 6 Problem 2
// Due Date: Thursday 4/7/2022
// Purpose: This application accepts a
// sentence and displays the words on
// separate lines.
//--------------------------------------

#include <iostream>
//#include <cstring>
using namespace std;

char sentence[50], c;
int i;

void readSentence()
{
    cout << "Enter a sentence: ";
    cin.getline(sentence, 50, '\n');
}

void display()
{
    cout << c;
}

void newLine()
{
    cout << endl;
}

int main()
{
    _asm
    {
            call readSentence
            lea esi, sentence
            mov dl, [esi]
        loopy:
            cmp dl, '\0'
            je endLoopy
            mov c, dl
            call display
            inc esi
            mov dl, [esi]
            cmp dl, ' '
            jne loopy
            call newLine
            inc esi
            mov dl, [esi]
            jmp loopy
        endLoopy:
    }
    system("pause");
    return 0;
}