//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 7 Problem 2
// Due Date: Thursday 4/28/2022
// Purpose: This application displays
// totals from a 3-dimensional array.
//--------------------------------------
#include <iostream>
using namespace std;

int b[4][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
int i, total, maintotal, femaletotal, maleirvine;

void displayTotal()
{
    cout << "The total number of students: ";
    _asm
    {
            mov eax, 0
            mov i, 0
            lea esi, b
        forLoop :
            cmp i, 24
            je done
            add eax, [esi]
            add esi, 4
            inc i
            jmp forLoop
        done :
            mov total, eax
    }
    cout << total << endl;
}

void displayMainTotal()
{
    cout << "The total number of students in Main campus: ";
    _asm
    {
            mov eax, 0
            mov i, 0
            lea esi, b
        forLoop :
            cmp i, 8
            je done
            add eax, [esi]
            add esi, 12
            inc i
            jmp forLoop
        done :
            mov maintotal, eax
    }
    cout << maintotal << endl;
}

void displayFemaleTotal()
{
    cout << "The total number of female students: ";
    _asm
    {
            mov eax, 0
            mov i, 0
            lea esi, b
            add esi, 48
        forLoop :
            cmp i, 12
            je done
            add eax, [esi]
            add esi, 4
            inc i
            jmp forLoop
        done :
            mov femaletotal, eax
    }
    cout << femaletotal << endl;
}

void displayMaleIrvine()
{
    cout << "The total number of male students in the Irvine campus: ";
    _asm
    {
            mov eax, 0
            mov i, 0
            lea esi, b
            add esi, 4
        forLoop :
            cmp i, 4
            je done
            add eax, [esi]
            add esi, 12
            inc i
            jmp forLoop
        done :
            mov maleirvine, eax
    }
    cout << maleirvine << endl;
}

int main()
{
    displayTotal();
    displayMainTotal();
    displayFemaleTotal();
    displayMaleIrvine();

    system("pause");
    return 0;
}