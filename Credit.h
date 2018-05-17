#ifndef CREDIT_H_INCLUDED
#define CREDIT_H_INCLUDED
#include <iostream>

class PaymentDate
{
public:
    PaymentDate();
    PaymentDate(const int& enteredDd, const int& enteredMm, const int& enteredYy);
    ~PaymentDate();
    //*******SET********
    void setdd(const int& enteredDd);
    void setmm(const int& enteredMm);
    void setyy(const int& enteredYy);
    //********GET********
    int getdd();
    int getmm();
    int getyy();
    //*******************
private:
    int dd;
    int mm;
    int yy;
};

class Credit
{
public:
    Credit();
    Credit(const int& enteredLoanAmount, const float& enteredInterestRate, const int& enteredContributionNumber, PaymentDate enteredPd);
    ~Credit();
    //*******SET********
    void setLoanAmount(const int& enteredLoanAmount);
    void setInterestRate(const float& enteredInterestRate);
    void setContributionNumber(const int& enteredContributionNumber);
    //********GET********
    int getLoanAmount();
    float getInterestRate();
    int getContributionNumber();
    //*******************
private:
    int loanAmount;
    float interestRate;
    int contributionNumber;
    PaymentDate pd; // Credit has a paymentDate.
};

//******GENERATE*****
void generateAmmortizationSchedule(Credit dataInput, PaymentDate dataInputPD);
void generateAmmortizationSchedule(Credit dataInput, Credit dataWithChangesInput, PaymentDate dataInputPD, PaymentDate dataPDWithChangesInput);
//******PRINT********
void printToTextFileBackground();
void printToTextFile(int pc /*paymentCounter*/, float ra/*remainingAmount*/, float pp/*principalPayment*/, float ip /*interestPayment*/,
                     float tp/*totalPayment*/, float ir/*interestRate*/, int m/*mm*/, int d/*dd*/, int y/*yy*/);
//*******************

#endif // CREDIT_H_INCLUDED
