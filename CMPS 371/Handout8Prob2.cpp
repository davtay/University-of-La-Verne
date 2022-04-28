//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 8 Problem 2
// Due Date: Thursday 5/05/2022
// Purpose: This application returns
// the area of a triangle.
//--------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

float s1, s2, s3, p, pa, pb, pc, pall, two = 2, area;

void inputData()
{
	cout << "Enter the length of the three sides of a triangle: ";
	cin >> s1 >> s2 >> s3;
}

void areaTriangle()
{
	_asm
	{
		fld s1
		fld s2
		fadd
		fld s3
		fadd
		fld two
		fdiv
		fstp p

		fld p
		fld s1
		fsub
		fstp pa

		fld p
		fld s2
		fsub
		fstp pb

		fld p
		fld s3
		fsub
		fstp pc

		fld p
		fld pa
		fmul
		fld pb
		fmul
		fld pc
		fmul
		fsqrt
		fstp area
	}
}

int main()
{
	inputData();
	areaTriangle();
	cout << fixed << showpoint << setprecision(2);
	cout << "    Area = " << area << endl;

	system("pause");
	return 0;
}