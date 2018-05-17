#include "Credit.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

void generateAmmortizationSchedule(Credit dataInput, PaymentDate dataPDInput)
{
    //***************************VARIABLES***************************
    int paymentCounter = 1; // counts quantity of payments
    int contributionNumberCounter = dataInput.getContributionNumber();  // counts quantity of contributions
    float annualInterestRate = 1 + ((dataInput.getInterestRate() / 100) / 12); // annualInterestRate – interestRate = 1 + interest_rate_per_time_period
    float remainingAmount = dataInput.getLoanAmount();
    float interestPayment = round((remainingAmount * (annualInterestRate * (pow(1 + annualInterestRate, contributionNumberCounter)) / pow((1 + annualInterestRate),contributionNumberCounter) - 1)) * 100) / 100;
    //interest payment formula, rounds up to two places
    float principalPayment = floor((remainingAmount * (pow(annualInterestRate, contributionNumberCounter) * (annualInterestRate - 1)) / (pow(annualInterestRate, contributionNumberCounter) - 1)- interestPayment) * 100) / 100;
    // principal payment formula, rounds up to two places
    float totalPayment = floor((interestPayment + principalPayment) * 100) / 100; // total payment formula rounded up to 2 places
    //*************************SET_BACKGROUND************************
    printToTextFileBackground();
    //***************************************************************
    while(contributionNumberCounter != 0)
    {
        if (contributionNumberCounter == 1)
        {
            interestPayment = round((remainingAmount * (annualInterestRate * (pow(1 + annualInterestRate, contributionNumberCounter)) / pow((1 + annualInterestRate),contributionNumberCounter) - 1)) * 100) / 100;
            //interest payment formula rounded up to 2 places
            totalPayment = remainingAmount + interestPayment;
            //****************PRINT_TO_TEXT_FILE***************
            printToTextFile(paymentCounter,remainingAmount,principalPayment,interestPayment,totalPayment,dataInput.getInterestRate(), dataPDInput.getmm(), dataPDInput.getdd(), dataPDInput.getyy());
            // prints last payment.
            break; // breaks while() to not get errors in calculations.
        }
        //****************PRINT_TO_TEXT_FILE***************
        printToTextFile(paymentCounter,remainingAmount,principalPayment,interestPayment,totalPayment,dataInput.getInterestRate(), dataPDInput.getmm(), dataPDInput.getdd(), dataPDInput.getyy());
        if(dataPDInput.getmm() == 12) // checks if it is twelfth month
        {
            dataPDInput.setmm(1); // sets to the first month
            dataPDInput.setyy(dataPDInput.getyy() + 1); // adds one year to the current year
        }
        else
        {
            dataPDInput.setmm(dataPDInput.getmm() + 1); //adds one month to the current month
        }
        contributionNumberCounter--; // minus contribution number (^n)
        remainingAmount = floor((remainingAmount - principalPayment) * 100) / 100; // calculates and rounds up to two places
        interestPayment = round((remainingAmount * (annualInterestRate * (pow(1 + annualInterestRate, contributionNumberCounter)) / pow((1 + annualInterestRate),contributionNumberCounter) - 1)) * 100) / 100;
        // interest payment formula, rounds up to two places
        principalPayment = floor((remainingAmount * (pow(annualInterestRate, contributionNumberCounter) * (annualInterestRate - 1)) / (pow(annualInterestRate, contributionNumberCounter) - 1) - interestPayment) * 100) / 100;
        // principal payment formula, rounds up to two places
        paymentCounter++; // counts quantity of payments
    }
}

void generateAmmortizationSchedule(Credit dataInput, Credit dataWithChangesInput, PaymentDate dataPDInput, PaymentDate dataPDWithChangesInput)
{
    //***************************VARIABLES***************************
    int paymentCounter = 1; // counts quantity of payments
    int contributionNumberCounter = dataInput.getContributionNumber(); // counts quantity of contributions
    float annualInterestRate = 1 + ((dataInput.getInterestRate() / 100) / 12); // annualInterestRate – interestRate = 1 + interest_rate_per_time_period
    float remainingAmount = dataInput.getLoanAmount();
    float interestPayment = round((remainingAmount * (annualInterestRate * (pow(1+annualInterestRate, contributionNumberCounter)) / pow((1 + annualInterestRate),contributionNumberCounter) - 1)) * 100) / 100;
    // interest payment formula, rounds up to two places
    float principalPayment = floor((remainingAmount * (pow(annualInterestRate, contributionNumberCounter) * (annualInterestRate - 1)) / (pow(annualInterestRate, contributionNumberCounter) - 1) - interestPayment) * 100) / 100;
    // principal payment formula, rounds up to two places
    float totalPayment = floor((interestPayment + principalPayment) * 100) / 100;
    //*************************SET_BACKGROUND************************
    printToTextFileBackground();

    while((dataPDInput.getmm() != dataPDWithChangesInput.getmm()) || (dataPDInput.getyy() != dataPDWithChangesInput.getyy()))
    {
        if (contributionNumberCounter == 1)
        {
            interestPayment = round((remainingAmount * (annualInterestRate * (pow(1 + annualInterestRate, contributionNumberCounter))/pow((1 + annualInterestRate),contributionNumberCounter)-1))*100)/100;
            totalPayment = remainingAmount + interestPayment;
            //****************PRINT_TO_TEXT_FILE***************
            printToTextFile(paymentCounter,remainingAmount,principalPayment,interestPayment,totalPayment,dataInput.getInterestRate(), dataPDInput.getmm(), dataPDInput.getdd(), dataPDInput.getyy());
            break; // breaks while() to not get errors in calculations.
        }
        //****************PRINT_TO_TEXT_FILE***************
        printToTextFile(paymentCounter,remainingAmount,principalPayment,interestPayment,totalPayment,dataInput.getInterestRate(), dataPDInput.getmm(), dataPDInput.getdd(), dataPDInput.getyy());
        if(dataPDInput.getmm() == 12)
        {
            dataPDInput.setmm(1);
            dataPDInput.setyy(dataPDInput.getyy()+1);
        }
        else
        {
            dataPDInput.setmm(dataPDInput.getmm() + 1);
        }
        contributionNumberCounter --;
        remainingAmount = floor((remainingAmount - principalPayment) * 100) / 100;
        interestPayment = round((remainingAmount * (annualInterestRate * (pow(1 + annualInterestRate, contributionNumberCounter)) / pow((1 + annualInterestRate),contributionNumberCounter) - 1)) * 100) / 100;
        principalPayment = floor((remainingAmount * (pow(annualInterestRate, contributionNumberCounter) * (annualInterestRate - 1)) / (pow(annualInterestRate, contributionNumberCounter) - 1)- interestPayment) * 100) / 100;
        paymentCounter++;
    }
    //***************CALCULATIONS***************
    annualInterestRate = 1 + ((dataWithChangesInput.getInterestRate() / 100) / 12); // sets new annual interest rate
    interestPayment = round((remainingAmount * (annualInterestRate * (pow(1 + annualInterestRate, contributionNumberCounter)) / pow((1 + annualInterestRate),contributionNumberCounter) - 1)) * 100) / 100;
    principalPayment = floor((remainingAmount * (pow(annualInterestRate, contributionNumberCounter) * (annualInterestRate - 1)) / (pow(annualInterestRate, contributionNumberCounter) - 1) - interestPayment) * 100) / 100;
    totalPayment = floor((interestPayment + principalPayment) * 100) / 100;
    //*****************************************
    while(contributionNumberCounter != 0)
    {
        if (contributionNumberCounter == 1)
        {
            interestPayment = round((remainingAmount * (annualInterestRate * (pow(1 + annualInterestRate, contributionNumberCounter)) / pow((1 + annualInterestRate),contributionNumberCounter) - 1)) * 100) / 100;
            totalPayment = remainingAmount + interestPayment;
            //****************PRINT_TO_TEXT_FILE***************
            printToTextFile(paymentCounter,remainingAmount,principalPayment,interestPayment,totalPayment,dataWithChangesInput.getInterestRate(), dataPDInput.getmm(), dataPDInput.getdd(), dataPDInput.getyy());
            break;
        }
        //****************PRINT_TO_TEXT_FILE***************
        printToTextFile(paymentCounter,remainingAmount,principalPayment,interestPayment,totalPayment,dataWithChangesInput.getInterestRate(), dataPDInput.getmm(), dataPDInput.getdd(), dataPDInput.getyy());
        if(dataPDInput.getmm() == 12)
        {
            dataPDInput.setmm(1);
            dataPDInput.setyy(dataPDInput.getyy() + 1);
        }
        else
        {
            dataPDInput.setmm(dataPDInput.getmm() + 1);
        }
        //***************CALCULATIONS***************
        contributionNumberCounter --;
        remainingAmount = floor((remainingAmount - principalPayment) * 100) / 100;
        interestPayment = round((remainingAmount * (annualInterestRate * (pow(1 + annualInterestRate, contributionNumberCounter)) / pow((1 + annualInterestRate),contributionNumberCounter) - 1)) * 100) / 100;
        principalPayment = floor((remainingAmount * (pow(annualInterestRate, contributionNumberCounter) * (annualInterestRate - 1)) / (pow(annualInterestRate, contributionNumberCounter) - 1) - interestPayment) * 100) / 100;
        //*****************************************
        paymentCounter ++;
    }
}
//*****************PRINT_TO_TEXT_FILE************************
void printToTextFileBackground()
{
    ofstream out("results.csv", ios::app);
    if(!out)
        cerr << "Unable to open file" << endl;
    else
        out << "Payment #, Payment date, Remaining amount, Principal payment, Interest payment, Total payment, Interest rate" << endl;
    out.close();
}

void printToTextFile(int pc /*paymentCounter*/, float ra/*remainingAmount*/, float pp/*principalPayment*/, float ip /*interestPayment*/,
                     float tp/*totalPayment*/, float ir/*interestRate*/, int m/*mm*/, int d/*dd*/, int y/*yy*/)
{
    ofstream out("results.csv", ios::app);
    if(!out)
        cerr << "Unable to open file" << endl;
    else
    {
        out << pc << ",";
        out << m << "/" << d << "/" << y << ",";
        out << ra << ",";
        out << pp << ",";
        out << ip << ",";
        out << tp << ",";
        out << ir << ",";
        out << endl;
    }
    out.close();
}
//***********************************************************
