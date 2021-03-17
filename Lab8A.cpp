/*
Author: David Vargas (DavidVargas@my.unt.edu)
Date: 3/16/2021
Instructor: Polina Nemkova
Description:
*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char str1[30];
    char str2[60];
    int lengthStr1, lengthStr2;

    strcpy(str1, "This is C-String programming");
    cout<< "Tell me something: ";
    cin.getline(str2, 60);
    
    //Storing length of strings into varibles.
    lengthStr1 = strlen(str1);
    lengthStr2 = strlen(str2);

    //Comparing string lengths and informing user.
    if (lengthStr1 == lengthStr2)
    {
        cout << "Strings are the same length." << endl;
    }
    else
    {
        cout << "Strings are not the same length." << endl;
        return 0;
    }

    //Comparing string array character by character.
    if (strcmp(str1, str2) == 0)
    {
        cout << "These are the same string." << endl;
    }
    else
    {
        cout << "These are not the same string." << endl;
    }

    return 0;
}
