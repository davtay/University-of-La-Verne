//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 2 Problem 1
// Due Date: Thursday 2/24/2022
//--------------------------------------
#include <iostream>
using namespace std;

int leng, width, height, volume, sarea, a = 2;

int main()
{
    cout << "Please enter the length, width, and height of your object: ";
    cin >> leng >> width >> height;

    _asm
    {
        mov     eax, leng;
        imul    width;
        imul    height;
        mov     volume, eax;
        mov     eax, leng;
        imul    width;
        imul    a;
        mov     ebx, eax;
        mov     eax, leng;
        imul    height;
        imul    a;
        mov     ecx, eax;
        mov     eax, width;
        imul    height;
        imul    a;
        add     eax, ebx;
        add     eax, ecx;
        mov     sarea, eax;
    }

    cout << "Volume = " << volume << endl;
    cout << "Surface Area = " << sarea << endl;
    system("pause");
    return 0;
}