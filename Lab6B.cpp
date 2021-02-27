#include <iostream>
//#include <string>
using namespace std;

int main()
{
    enum Operation
    {
        Multiply = 'M',
        Add = 'A',
        Difference = 'D'
    };              //the operations
    int result;     //result of operation
    int num1, num2; //integers to perform operation on
    Operation my_operation;
    char choice;
    bool isNotValidInput = true;
    cout << "Enter two integers:";
    cin >> num1 >> num2;
    cout << num1 << num2 << endl;
    do
    {
        cout << "Enter M to Multiply, A to Add, and D for Difference: ";
        cin >> choice;

        my_operation = Operation(toupper(choice));
        //cout<<"My operation: "<< my_operation<< endl;
        switch (my_operation)
        {
        case Add:
            result = num1 + num2;
            //cout << 'A' << endl;
            isNotValidInput = false;
            break;

        case Multiply:
            result = num1 * num2;
            //cout << 'M' << endl;
            isNotValidInput = false;
            break;

        case Difference:
            result = num1 / num2;
            //cout << 'D' << endl;
            isNotValidInput = false;
            break;

        default:
            cout << "Invalid Input. Enter again: " << endl;
        }
    } while (isNotValidInput);
    cout << "The result of the operation is " << result << endl;

    return 0;
}