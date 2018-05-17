#include "Credit.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //*******VARIABLES********
    Credit data;
    PaymentDate dataPD;
    string enteredDate;
    //*******INTRODUCTION******
    cout << "This program generates ammortization schedule using annuity method." << endl;
    cout << "Please follow the instructions for the successful work of the program. " << endl;
    //*******PAYMENT_DATE******
    cout << "Please insert payment date in format mm/dd/yyyy (for example:. 05/15/2018) : ";
    cin >> enteredDate;
    dataPD.setmm(stoi(enteredDate.substr(0,2))); // reads mm
    dataPD.setdd(stoi(enteredDate.substr(3,2))); // reads dd
    dataPD.setyy(stoi(enteredDate.substr(6))); // reads yyyy
    //********LOAN_AMOUNT******
    cout << "Please insert loan amount: ";
    int enteredLoanAmount;
    cin >> enteredLoanAmount;
    data.setLoanAmount(enteredLoanAmount);
    //********INTEREST_RATE****
    cout << "Please insert interest rate: ";
    float enteredInterestRate;
    cin >> enteredInterestRate;
    data.setInterestRate(enteredInterestRate);
    //***CONTRIBUTION_NUMBER***
    cout << "Please insert contribution number: ";
    int enteredContributionNumber;
    cin >> enteredContributionNumber;
    data.setContributionNumber(enteredContributionNumber);
    //***********OPTIONS*******
    cout << "Credit has an option to change interest rate from certain payment date." << endl;
    cout << "Do we need to change it? Enter: 1 - Yes, 0 - No. ";
    cout << "Enter your option: ";
    int enteredOption;
    cin >> enteredOption;
    if (enteredOption == 1)
    {
        //*********NEW_VARIABLES************
        Credit dataWithChanges;
        PaymentDate dataPDWithChanges;
        //**********************************
        //********INTEREST_RATE*************
        cout << "Please insert new interest rate: ";
        cin >> enteredInterestRate;
        dataWithChanges.setInterestRate(enteredInterestRate);
        //********PAYMENT_DATE**************
        cout << "Please insert new payment date in format mm/dd/yyyy (for example:. 05/15/2018) : ";
        cin >> enteredDate;
        dataPDWithChanges.setmm(stoi(enteredDate.substr(0,2))); //reads mm
        dataPDWithChanges.setdd(stoi(enteredDate.substr(3,2))); // reads dd
        dataPDWithChanges.setyy(stoi(enteredDate.substr(6))); // reads yyyy
        //**********************************
        generateAmmortizationSchedule(data, dataWithChanges, dataPD, dataPDWithChanges); // Generates ammortization schedule
    }
    else if (enteredOption == 0)
        generateAmmortizationSchedule(data, dataPD); // Generates ammortization schedule
    else // Wrong enteredOption input ( != 0 || 1 )
    {
        cerr << "Wrong input. Try again." << endl;
    }
    return 0;
}
