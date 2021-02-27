#include <iostream>
//#include <string>

using namespace std;

int main()
{
    string userMessage;
    int totalLetter = 0;
    int lowerLetter = 0;
    int upperLetter = 0;
    int digits = 0;
    int specialCharacters = 0;
    int whiteSpace = 0;

    cout << "Say what's up dawg? ";
    getline(cin, userMessage);
    cout << userMessage << endl;

    for (int i = 0; userMessage.length()-1 >= i; i++)
    {

        cout << userMessage[i] << endl;
        if (isalpha(userMessage[i]))
        {
            totalLetter++;
            if (isupper(userMessage[i]))
            {
                upperLetter++;
            }
            else if (islower(userMessage[i]))
            {
                lowerLetter++;
            }
        }
        else if (isdigit(userMessage[i]))
        {
            digits++;
        }
        else if (isspace(userMessage[i]))
        {
            whiteSpace++;
        }
        else
        {
            specialCharacters++;
        }
    }
    cout << "total letter: " << totalLetter << endl;
    cout << "upper case: " << upperLetter << endl;
    cout << "lower Case: " << lowerLetter << endl;
    cout << "total special characters: " << specialCharacters << endl;
    cout << "total digits: " << digits << endl;
    cout << "total white space: " << whiteSpace << endl;
    return 0;
}
