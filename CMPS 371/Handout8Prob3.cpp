//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 8 Problem 3
// Due Date: Thursday 5/05/2022
// Purpose: This application returns
// the total bill.
//--------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

float drinks, s, w, j, hd, burg, total;
float soda = 1.25, water = 0.95, juice = 2.25;
float hotdog = 1.75, burger = 2.65;
float tsoda, twater, tjuice, thotdog, tburger;

void getData()
{
    cout << "----------MENU----------" << endl;
    cout << "Drinks" << endl;
    cout << "    Soda(s).........1.25" << endl;
    cout << "    Water(w)........0.95" << endl;
    cout << "    Juice(j)........2.25" << endl;
    cout << "Food" << endl;
    cout << "    Hotdogs.........1.75" << endl;
    cout << "    Burgers.........2.65" << endl;
    cout << "           How many drinks? ";
    // unused variable
    cin >> drinks;
    cout << "           Enter the number of sodas, waters, and juices: ";
    cin >> s >> w >> j;
    cout << "           How many hotdogs? ";
    cin >> hd;
    cout << "           How many burgers? ";
    cin >> burg;
}

void computeTotal()
{
    _asm
    {
        fld soda
        fld s
        fmul
        fstp tsoda

        fld water
        fld w
        fmul
        fstp twater

        fld juice
        fld j
        fmul
        fstp tjuice

        fld hotdog
        fld hd
        fmul
        fstp thotdog

        fld burger
        fld burg
        fmul
        fstp tburger

        fld tsoda
        fld twater
        fadd
        fld tjuice
        fadd
        fld thotdog
        fadd
        fld tburger
        fadd
        fstp total
    }
}

int main()
{
    getData();
    computeTotal();
    cout << fixed << showpoint << setprecision(2);
    cout << "             Your total bill = $" << total << endl;

    system("pause");
    return 0;
}