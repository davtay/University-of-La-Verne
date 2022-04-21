//--------------------------------------
// Name: David Taylor
// Course: CMPS 371
// Assignment: Handout 5 Problem 1
// Due Date: Thursday 3/24/2022
// Purpose: This application computers how
// many sprinklers from a binary number
//--------------------------------------
#include <iostream>
#include <string>
using namespace std;

char hexinput[10] = "F47E";
string binaryNumber = "";
int right_sprinklers, left_sprinklers, total_sprinklers, l, c;

void convertHextoBinary(string hexinput) {
    int i = 0;
    while (hexinput[i]) {
        switch(hexinput[i]) {
            case '0':
                binaryNumber = binaryNumber + "0000";
                break;
            case '1':
                binaryNumber = binaryNumber + "0001";
                break;
            case '2':
                binaryNumber = binaryNumber + "0010";
                break;
            case '3':
                binaryNumber = binaryNumber + "0011";
                break;
            case '4':
                binaryNumber = binaryNumber + "0100";
                break;
            case '5':
                binaryNumber = binaryNumber + "0101";
                break;
            case '6':
                binaryNumber = binaryNumber + "0110";
                break;
            case '7':
                binaryNumber = binaryNumber + "0111";
                break;
            case '8':
                binaryNumber = binaryNumber + "1000";
                break;
            case '9':
                binaryNumber = binaryNumber + "1001";
                break;
            case 'A':
                binaryNumber = binaryNumber + "1010";
                break;
            case 'B':
                binaryNumber = binaryNumber + "1011";
                break;
            case 'C':
                binaryNumber = binaryNumber + "1100";
                break;
            case 'D':
                binaryNumber = binaryNumber + "1101";
                break;
            case 'E':
                binaryNumber = binaryNumber + "1110";
                break;
            case 'F':
                binaryNumber = binaryNumber + "1111";
                break;
        }
        i++;
    }
}

int main()
{
    convertHextoBinary(hexinput);
    cout << "Content of ax register = " << binaryNumber << endl;

    _asm
    {
                mov eax, 1111010001111110b
                mov ecx, 16
                mov c, 1
                mov ebx, 0
                mov edx, 0
        doLoop :
                cmp ecx, 0
                je done
                and c, eax
                cmp c, 1
                je add_1_right
                jmp cont
        doLoopLeft :
                cmp ecx, 0
                je done
                and c, eax
                cmp c, 1
                je add_1_left
                jmp contLeft
        add_1_right :
                inc ebx
        add_1_left :
                inc edx
        cont :
                mov c, 1
                dec ecx
                shr eax, 1
                cmp ecx, 8
                jg doLoop
                jle doLoopLeft
        contLeft :
                mov c, 1
                dec ecx
                shr eax, 1
                jmp doLoopLeft
        done :
                mov left_sprinklers, ebx
                mov total_sprinklers, edx
    }

    right_sprinklers = total_sprinklers - left_sprinklers;
    cout << "Number of sprinklers watering left side = " << left_sprinklers << endl;
    cout << "Number of sprinklers watering right side = " << right_sprinklers << endl;

    system("pause");
    return 0;
}