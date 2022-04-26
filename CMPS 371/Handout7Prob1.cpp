//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 7 Problem 1
// Due Date: Thursday 4/28/2022
// Purpose: This application creates a
// 2-dimensional array from random numbers
// and manipulates the values.
//--------------------------------------
#include <iostream>
using namespace std;

short a[4][4], num, x, total, diagtotal, row, rowtotal;
int i, four;

void generateRand()
{
    num = rand() % 20;
}

void storeData()
{
    _asm
    {
            lea esi, a
            mov i, 0
        forLoop :
            cmp i, 16
            je done
            call generateRand
            mov ax, num
            mov [esi], ax
            add esi, 2
            inc i
            jmp forLoop
        done :
    }
}

void display()
{
    cout << x << "\t";
}

void nextLine()
{
    cout << endl;
}

void displayData()
{
    _asm
    {
            mov four, 4
            lea esi, a
            mov i, 0
        forLoop :
            cmp i, 16
            je done
            mov ax, [esi]
            mov x, ax
            call display
            add esi, 2
            inc i
            mov eax, i
            cdq
            idiv four
            cmp edx, 0
            je skipLine
            jmp forLoop
        skipLine :
            call nextLine
            jmp forLoop
        done :
    }
}

void computeTotal()
{
    _asm
    {
            mov ax, 0
            mov i, 0
            lea esi, a
        forLoop :
            cmp i, 16
            je done
            add ax, [esi]
            add esi, 2
            inc i
            jmp forLoop
        done :
            mov total, ax
    }
}

void displayTotal()
{
    cout << "The total is: " << total << endl;
}

void displayVal()
{
    cout << x << " ";
}

void displayRightDiag()
{
    cout << "The left-to-right diagonal values are: ";
    _asm
    {
            lea esi, a
            mov i, 0
        forLoop :
            cmp i, 4
            je done
            mov ax, [esi]
            mov x, ax
            call displayVal
            add esi, 10
            inc i
            jmp forLoop
        done :
    }
    cout << endl;
}

void displayTotalLeftDiag()
{
    cout << "The right-to-left diagonal total is: ";
    _asm
    {
            lea esi, a
            add esi, 6
            mov ax, 0
            mov i, 0
        forLoop :
            cmp i, 4
            je done
            add ax, [esi]
            add esi, 6
            inc i
            jmp forLoop
        done :
            mov diagtotal, ax
    }
    cout << diagtotal << endl;
}

void randomRow()
{
    row = rand() % 4;
}

void computeTotalRow()
{
    // Add 1 to row so numbers is 1-4 in output
    cout << "The total for row " << row+1 << " is: ";
    _asm
    {
            lea esi, a
            mov i, 0
            mov bx, 0
            mov eax, 8
            imul row
            add esi, eax
        forLoop :
            cmp i, 4
            je done
            add bx, [esi]
            add esi, 2
            inc i
            jmp forLoop
        done :
            mov rowtotal, bx
    }
    cout << rowtotal << endl;
}

int main()
{
    srand(time(NULL));
    storeData();
    displayData();
    computeTotal();
    displayTotal();
    displayRightDiag();
    displayTotalLeftDiag();
    randomRow();
    computeTotalRow();

    system("pause");
    return 0;
}