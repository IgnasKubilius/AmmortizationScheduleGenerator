#include "Credit.h"
#include <iostream>
using namespace std;
//*************************PAYMENTDATE_CLASS*******************************
//****************CONSTRUCTOR***************
PaymentDate::PaymentDate()
{
    dd = 1;
    mm = 1;
    yy = 1;
}
PaymentDate::PaymentDate(const int& enteredDd, const int& enteredMm, const int& enteredYy)
{
    dd = enteredDd;
    mm = enteredMm;
    yy = enteredYy;
}
//****************DESTRUCTOR****************
PaymentDate::~PaymentDate()
{

}
//*******************SET********************
void PaymentDate::setdd(const int& enteredDd)
{
    dd = enteredDd;
}
void PaymentDate::setmm(const int& enteredMm)
{
    mm = enteredMm;
}
void PaymentDate::setyy(const int& enteredYy)
{
    yy = enteredYy;
}
//*******************GET********************
int PaymentDate::getdd()
{
    return dd;
}
int PaymentDate::getmm()
{
    return mm;
}
int PaymentDate::getyy()
{
    return yy;
}
//*************************CREDIT_CLASS*******************************
//****************CONSTRUCTOR***************
Credit::Credit()
{
    loanAmount = 0;
    interestRate = 0;
    contributionNumber = 0;
}
Credit::Credit(const int& enteredLoanAmount, const float& enteredInterestRate, const int& enteredContributionNumber, PaymentDate enteredPd)
{
    loanAmount = enteredLoanAmount;
    interestRate = enteredInterestRate;
    contributionNumber = enteredContributionNumber;
    pd = enteredPd;
}
//****************DESTRUCTOR****************
Credit::~Credit()
{

}
//*******************SET********************
void Credit::setLoanAmount(const int& enteredLoanAmount)
{
    loanAmount = enteredLoanAmount;
}
void Credit::setInterestRate(const float& enteredInterestRate)
{
    interestRate = enteredInterestRate;
}
void Credit::setContributionNumber(const int& enteredContributionNumber)
{
    contributionNumber = enteredContributionNumber;
}
//*******************GET********************
int Credit::getLoanAmount()
{
    return loanAmount;
}
float Credit::getInterestRate()
{
    return interestRate;
}
int Credit::getContributionNumber()
{
    return contributionNumber;
}
//******************************************
