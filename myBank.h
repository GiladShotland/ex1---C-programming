#ifndef MYBANK
#define MYBANK
#include <stdio.h>
int openAccount(); 
double balanceInquiry(int account);
double deposit(int account);
double withdrawal(int account);
int closeAccount(int account);
int interest();
int print();
void exit1();
#endif //myBank