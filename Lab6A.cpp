#include <iostream>
//#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    srand (time(NULL)); //seeding the random varible

    int ranOne= rand() %100 + 1;
    int ranTwo=rand() %200 + 101;
    int sum=0;
    int ranOneCopy = ranOne;



    while(ranOne <= ranTwo){
        sum += ranOne;
        ranOne++;
    }

    cout<<"Random 1: "<< ranOneCopy << endl;
    cout<<"Random 2: "<< ranTwo << endl;
    cout<<"Sum: "<< sum << endl;

    return 0;
}