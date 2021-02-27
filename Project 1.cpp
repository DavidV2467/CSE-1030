#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
    cout << "+-------------------------------------------------+" << endl;
    cout << "|\t  Computer Science and Engineering\t  |" << endl;
    cout << "|\t CSCE 1030 - Computer Science I\t          |" << endl;
    cout << "|    David Vargas dav0090 davidvargas@my.unt.edu  |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    const float minBalanceBusiness = 10000.00;
    const float minBalancePersonal = 1000.00;
    float curBalanceBusiness = 10000.00;
    float curBalancePersonal = 1000.00;
    enum accType
    {
        Business,
        Personal
    };
    accType myaccount;
    string accountName;
    string accountNumber;
    int encryptedAccNum = 0;
    //int newAccountNum=0;
    double userTransaction = 0;
    int userInputAccountType;
    bool isValidName = false;
    bool isNotValidNumber = false;
    bool isNotValidAccount = true;
    double tempNumber = 0;
    char yesNo;

    srand(time(0));
    int randomEncrypt = rand() % (300000 - 200001) + 200001;

    //if(accountName.find() )
    //Your name can only have alphabets or spaces. Enter again.
    //Capitilize first character of each word in the string

    //user enters account name
    //UPDATE STRING FIRST LETTER CAPATILIZED: USE TOUPPER
    do
    {
        isValidName = false;
        cout << "Enter name of Account: ";
        getline(cin, accountName);
        //cout<< "Here is account name "<< accountName<<endl;
        for (int i = 0; i < accountName.size(); i++)
        {

            if (isalpha(accountName[i]) || isspace(accountName[i]))
            {
                if (i == 0)
                {
                    accountName[i] = toupper(accountName[i]);
                }
                else if (isspace(accountName[i]))
                {
                    accountName[i + 1] = toupper(accountName[i + 1]);
                }
                //cout<<accountName[i]<< "This is alpha"<<endl;
            }
            else
            {
                //cout<<accountName[i]<< "This is not alpha"<<endl;

                isValidName = true;
            }
        }

    } while (isValidName);

    //User enter account number
    //Requirement: MUST GIVE ERROR WHEN INPUTIS INVALID
    do
    {
        isNotValidNumber = false;
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        //cout << accountNumber.size();
        if (accountNumber.length() != 6)
        {
            cout << "Your account number is a 6-digit number. Enter again: " << endl;
            isNotValidNumber = true;
        }

    } while (isNotValidNumber);

    //Generating encrypted account number
    //newAccountNum= stoi(accountNumber);
    encryptedAccNum = randomEncrypt + stoi(accountNumber);
    // cout << "accountNumber: " << accountNumber << endl;
    // cout << "randomEncrypt: " << randomEncrypt << endl;
    // cout << "encryptedAccNum: " << encryptedAccNum << endl;
    // cout << "stringEncryptedAccNum: " << stringEncryptedAccNum << endl;
    string stringEncryptedAccNum = to_string(encryptedAccNum);
    if (stringEncryptedAccNum.length() > 6)
    {
        stringEncryptedAccNum[0] = ' ';
    }
    // cout << "_afterif: " << stringEncryptedAccNum << endl;

    do
    {
        //here lays switch-case block
        cout << "Enter 0 for Business Account, 1 for Personal: ";
        cin >> userInputAccountType;
        myaccount = accType(userInputAccountType);

        switch (myaccount)
        {
        case 0:
            cout << "Business" << endl;
            isNotValidAccount = false;
            cout << "Enter transaction: " << endl;
            cin >> userTransaction;
            curBalanceBusiness = curBalanceBusiness + userTransaction;
            if (curBalanceBusiness < minBalanceBusiness)
            {
                cout << "Your balance is less than the required minimum. There will be a $10.00 fee for every transaction." << endl;
                curBalanceBusiness -= 10;
                //cout << "Business Balance:$" << curBalanceBusiness << endl;
            }
            cout << "Do you want to process another transaction? Y/N: ";
            cin >> yesNo;
            if (toupper(yesNo) == 'N')
            {
                cout << "Name:" << accountName << endl;
                cout << "Account Number (Encrypted):" << stringEncryptedAccNum << endl;

                cout << "Business Balance:$" << fixed << setprecision(2) << curBalanceBusiness << endl;
                cout << "Personal Balance:$" << curBalancePersonal << endl;
                return 0;
            }
            else if (toupper(yesNo) == 'Y')
            {
                isNotValidAccount = true;
            }

            break;
        case 1:
            cout << "Personal" << endl;
            isNotValidAccount = false;
            cout << "Enter transaction: ";
            cin >> userTransaction;
            tempNumber = curBalancePersonal + userTransaction;
            if (tempNumber < minBalancePersonal)
            {
                cout << "Your personal balance cannot be less than minimum balance. Transaction denied." << endl;
                cout
                    << "Personal Balance:$" << curBalancePersonal << endl;
            }
            else
            {
                curBalancePersonal = curBalancePersonal + userTransaction;
                cout<< "Personal Balance:$"<< curBalancePersonal<<endl;
            }
            cout << "Do you want to process another transaction? Y/N: ";
            cin >> yesNo;
            if (toupper(yesNo) == 'N')
            {
                cout << "Name:" << accountName << endl;
                cout << "Account Number (Encrypted):" << stringEncryptedAccNum << endl;
                cout << "Business Balance:$" << curBalanceBusiness << ".00" << endl;
                cout << "Personal Balance:$" << curBalancePersonal << ".00" << endl;
                return 0;
            }
            else if (toupper(yesNo) == 'Y')
            {
                isNotValidAccount = true;
            }
            break;
        default:
            cout << "Wrong choice. Please enter again: " << endl;
        }

    } while (isNotValidAccount);

    // const float minBalanceBusiness = 10000.00;
    //     const float minBalancePersonal = 10000.00;
    //     float curBalanceBusiness = 10000.00;
    //     float curBalancePersonal = 1000.00;
    return 0;
}