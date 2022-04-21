//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 5 Problem 2
// Due Date: Thursday 3/24/2022
// Purpose: This application computes information
// about the computer from a binary number
//--------------------------------------
#include <iostream>
using namespace std;

int printers, drives, memory, terminals;

int main()
{
    cout << "Content of bx = 1100 1100 1100 0010" << endl;
   // cout << "Number of terminals are " << terminals << endl;

    _asm
    {
        mov eax, 1100110011000010b
        mov printers, 0xE000
        and printers, eax
        shr printers, 13
    }
    cout << "Number of printers are " << printers << endl;

    _asm
    {
        mov eax, 1100110011000010b
        mov drives, 0x0C00
        and drives, eax
        shr drives, 10
    }
    cout << "Number of disk drives are " << drives << endl;

    _asm
    {
        mov eax, 1100110011000010b
        mov memory, 0x01C0
        and memory, eax
        shr memory, 6
    }
    cout << "Memory size is " << memory << "G" << endl;

    _asm
    {
        mov eax, 1100110011000010b
        mov terminals, 0x0003
        and terminals, eax
    }
    cout << "Number of terminals are " << terminals << endl;

    system("pause");
    return 0;
}