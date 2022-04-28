//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 8 Problem 1
// Due Date: Thursday 5/05/2022
// Purpose: This application returns
// the volume and surface area of a
// cylinder and cone.
//--------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

float rcyl = 10.05, hcyl = 20.11, rcon = 9, hcon = 20, pi = 3.14;
float vcyl, sacyl, vcon, sacon, two = 2, three = 3;
float cyls1, cyls2, cons1, cons2;

void volumeCylinder()
{
    _asm
    {
        fld pi
        fld rcyl
        fmul
        fld rcyl
        fmul
        fld hcyl
        fmul
        fstp vcyl
    }
}

void surfaceAreaCylinder()
{
    _asm
    {
        fld two
        fld pi
        fmul
        fld rcyl
        fmul
        fld rcyl
        fmul
        fstp cyls1

        fld two
        fld pi
        fmul
        fld rcyl
        fmul
        fld hcyl
        fmul
        fstp cyls2

        fld cyls1
        fld cyls2
        fadd
        fstp sacyl
    }
}

void volumeCone()
{
    _asm
    {
        fld pi
        fld rcon
        fmul
        fld rcon
        fmul
        fld hcon
        fmul
        fld three
        fdiv
        fstp vcon
    }
}

void surfaceAreaCone()
{
    _asm
    {
        fld pi
        fld rcon
        fmul
        fld rcon
        fmul
        fstp cons1

        fld pi
        fld rcon
        fmul
        fld hcon
        fmul
        fstp cons2

        fld cons1
        fld cons2
        fadd
        fstp sacon
    }
}

int main()
{
    volumeCylinder();
    surfaceAreaCylinder();
    volumeCone();
    surfaceAreaCone();
    cout << fixed << showpoint << setprecision(2);
    cout << "Volume of the cylinder: " << vcyl << " inches cubed" << endl;
    cout << "Surface area of the cylinder: " << sacyl << " inches squared" << endl;
    cout << "Volume of the cone: " << vcon << " inches cubed" << endl;
    cout << "Surface area of the cone: " << sacon << " inches squared" << endl;

    system("pause");
    return 0;
}