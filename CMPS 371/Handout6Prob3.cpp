//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 6 Problem 3
// Due Date: Thursday 4/7/2022
// Purpose: This application accepts a
// sentence and displays every 2 words
// on separate lines.
//--------------------------------------

#include <iostream>
//#include <cstring>
using namespace std;

char sentence[70], c;
int i;

void readSentence()
{
    cout << "Enter a sentence: ";
    cin.getline(sentence, 70, '\n');
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
        mov i, 0
        loopy:
        cmp dl, '\0'
            je endLoopy
            mov c, dl
            call display
            inc esi
            mov dl, [esi]
            cmp dl, ' '
            jne loopy
            jmp spaceCounter
            spaceCounter :
        inc i
            cmp i, 2
            jne loopy
            call newLine
            mov i, 0
            inc esi
            mov dl, [esi]
            jmp loopy
            endLoopy :
    }
    cout << endl;
    system("pause");
    return 0;
}