#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const double _minBalanceBusiness = 10000.00;
const double _minBalancePersonal = 1000.00;
const int _accountNumberLength = 6;
const int _maxTrasaction = 20;

enum accType
{
    Business,
    Personal
};

string getName()
{
    string accountName;
    bool isValidName = false;
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
    return accountName;
}

string getAccountNumber()
{
    string accountNumber;
    bool isNotValidNumber = false;
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
    return accountNumber;
}

string encrypt_num(string accountNumber)
{
    srand(time(0));
    int randomEncrypt = rand() % (300000 - 200001) + 200001;

    int encryptedAccNum = 0;
    //Generating encrypted account number
    encryptedAccNum = randomEncrypt + stoi(accountNumber);
    string stringEncryptedAccNum = to_string(encryptedAccNum);
    // cout << "accountNumber: " << accountNumber << endl;
    // cout << "randomEncrypt: " << randomEncrypt << endl;
    // cout << "encryptedAccNum: " << encryptedAccNum << endl;
    // cout << "stringEncryptedAccNum: " << stringEncryptedAccNum << endl;
    if (stringEncryptedAccNum.length() > 6)
    {
        stringEncryptedAccNum[0] = ' ';
    }
    return stringEncryptedAccNum;
}

void display_transactions(double transactions[2][_maxTrasaction], int numTrans, accType myaccount, bool isSort)
{
    int userInputAccountType;
    char yesNo;

    cout << "Which account to display? 0 for Business, 1 for Personal:";
    cin >> userInputAccountType;
    myaccount = accType(userInputAccountType);
    cout << "Do you want to sort? Y/N:" << endl;
    cin >> yesNo;
    if (tolower(yesNo) == 'y')
    {
        isSort = true;
    }
    switch (myaccount)
    {
    case 0:
        for (int i = 0; i <= _maxTrasaction; i++)
        {
            cout << transactions[0][i] << endl;
        }
    case 1:
        for (int j = 0; j <= _maxTrasaction; j++)
        {
            cout << transactions[1][j] << endl;
        }
    }
}

void process_account(double transactions[][_maxTrasaction], int numBusinessTransactions, int numPersonalTransactions, double curBalanceBusiness, double curBalancePersonal)
{
    accType myaccount;
    int userInputAccountType;
    bool isNotValidNumber = false;
    double userTransaction = 0;
    bool isNotValidAccount = true;
    char yesNo;
    string accountName;
    string stringEncryptedAccNum;
    double tempNumber = 0;
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
            if (curBalanceBusiness < _minBalanceBusiness)
            {
                cout << "Your balance is less than the required minimum. There will be a $10.00 fee for every transaction." << endl;
                curBalanceBusiness -= 10;
                //cout << "Business Balance:$" << curBalanceBusiness << endl;
            }
            transactions[0][numBusinessTransactions] = userTransaction;
            numBusinessTransactions = numBusinessTransactions + 1;

            cout << "Do you want to process another transaction? Y/N: ";
            cin >> yesNo;
            if (toupper(yesNo) == 'N')
            {
                cout << "Name:" << accountName << endl;
                cout << "Account Number (Encrypted):" << stringEncryptedAccNum << endl;

                cout << "Business Balance:$" << fixed << setprecision(2) << curBalanceBusiness << endl;
                cout << "Personal Balance:$" << curBalancePersonal << endl;
                return;
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
            if (tempNumber < _minBalancePersonal)
            {
                cout << "Your personal balance cannot be less than minimum balance. Transaction denied." << endl;
                cout
                    << "Personal Balance:$" << curBalancePersonal << endl;
            }
            else
            {
                curBalancePersonal = curBalancePersonal + userTransaction;
                cout << "Personal Balance:$" << curBalancePersonal << endl;
                transactions[1][numPersonalTransactions] = userTransaction;
                numPersonalTransactions = numPersonalTransactions + 1;
            }

            cout << "Do you want to process another transaction? Y/N: ";
            cin >> yesNo;
            if (toupper(yesNo) == 'N')
            {
                cout << "Name:" << accountName << endl;
                cout << "Account Number (Encrypted):" << stringEncryptedAccNum << endl;
                cout << "Business Balance:$" << curBalanceBusiness << ".00" << endl;
                cout << "Personal Balance:$" << curBalancePersonal << ".00" << endl;
                return;
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
}

int main()
{
    cout << "+-------------------------------------------------+" << endl;
    cout << "|\t  Computer Science and Engineering\t  |" << endl;
    cout << "|\t CSCE 1030 - Computer Science I\t          |" << endl;
    cout << "|    David Vargas dav0090 davidvargas@my.unt.edu  |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    double curBalanceBusiness = 10000.00;
    double curBalancePersonal = 1000.00;
    accType myaccount;
    enum actions
    {
        Process = 1,
        Display = 2,
        Quit = 3
    };
    actions myActions;
    string accountName;
    string accountNumber;
    string stringEncryptedAccNum;
    int encryptedAccNum = 0;
    //int newAccountNum=0;

    double transactions[2][_maxTrasaction];
    //transactions
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= _maxTrasaction; j++)
        {

            transactions[i][j] = 0;
        }
    }

    int userInputAction;
    int userInputAccountType;
    int numBusinessTransactions = 0;
    int numPersonalTransactions = 0;
    int numTrans = 0;
    bool isValidName = false;
    bool isSort = false;
    bool isNotQuit = true;

    srand(time(0));
    int randomEncrypt = rand() % (300000 - 200001) + 200001;

    //Asking user for account name.
    accountName = getName();

    //Asking user for account number.
    accountNumber = getAccountNumber();

    stringEncryptedAccNum = encrypt_num(accountNumber);

    //Prompt user for action.
    do
    {
        cout << "1. Process Accounts" << endl;
        cout << "2. Display Account Information" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> userInputAction;
        myActions = actions(userInputAction);
        switch (myActions)
        {
        case 1:
            cout << "Process Accounts" << endl;
            process_account(transactions, numBusinessTransactions, numPersonalTransactions, curBalanceBusiness, curBalancePersonal);
            break;
        case 2:
            cout << "Display Account Information" << endl;
            display_transactions(transactions, numTrans, myaccount, isSort);
            break;
        case 3:
            cout << "Goodbye!!" << endl;
            isNotQuit = false;
        }
    } while (isNotQuit);

    return 0;
}
