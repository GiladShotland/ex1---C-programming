#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
#define BANKSIZE 50
int numAccounts;
double accounts [2][50];
int openAccount(); 
double balanceInquiry(int account);
double deposit(int account);
double withdrawal(int account);
int closeAccount(int account);
int interest();
int print();
void exit1();

int openAccount(){
    if(numAccounts < BANKSIZE){
        double amount;
       
        printf("Please enter amount for deposit: ");
        if(scanf(" %lf",&amount) == 0){
            return -1;}
        if(amount<0){
            return -2;
        }
    
        int i;
        for (i = 0 ; i < BANKSIZE ; i++){
            if(accounts[0][i] == 0 ){
                accounts[0][i] = 1;
                break;
            }
        }
        
        accounts[1][i] = amount;
    
        numAccounts ++;
        i += 901;
        return i;
    }
    return 0;
}

double balanceInquiry(int account){
    if(account < 901 || account > 950){
        return -1;
    }
    account = account - 901;
    if(accounts[0][account] == 0){
        return 0;
    }
    else{
       
        return accounts[1][account];

    }
}

double deposit(int account){
    if(account < 901 || account > 950){
        return -2;
    }

    account = account - 901;
    if(!(int)accounts[0][account]){
        return 0;
    
    }
    else{
        printf("Please enter amount for deposit: ");
        double amount;
        if(scanf("%lf" , &amount)){
            fflush(stdin);
        
            if(amount < 0){
            return -3;
            }
            accounts [1][account] += amount;
            return accounts[1][account];
        }
        else{
            fflush(stdin);
            return -1;
        }
        
    }
}
double withdrawal(int account){
    if(account > 950 || account < 901){
        return -3;
    }

    account = account - 901;
    if(!(int)accounts[0][account]){
        return 0;
    }
    printf("Please enter the amount to withdraw: ");
    double draw;

    if(scanf("%lf" , &draw) == 0 ){
        return -1;
    }
    fflush(stdin);
    if(draw > balanceInquiry(account + 901)){
        return -2;
    }
    accounts[1][account] -= draw;
    return accounts[1][account];

}

int closeAccount(int account){
    account -= 901;
    if(!(int)accounts[0][account]){
        return 0;
    }
    else{
        accounts[0][account] = 0;
        accounts[1][account] = 0;
        numAccounts --;
        return 1;
    }
}

int interest(){
    int ratio;
    printf("Please enter interest rate: ");
    if(scanf(" %d" , &ratio) == 0){
        return 0;
    }
    if(ratio < 0){
        return -1;
    }
    int i;
    for (i = 0 ; i < BANKSIZE ; i++){
        if(accounts[0][i]){
            
            accounts[1][i] *= (1+(float)ratio/100);
            
        }
    }
    return 1;

}
int print (){
    if(!numAccounts){
        return 0;
    }
    else{
        int i;
        for( i = 0 ; i < BANKSIZE ; i++){
            if(accounts[0][i] != 0){
                printf("The balance of account %d is: %.2lf \n" ,i+901,accounts[1][i]);
            
            }
        }
        return 1;
    }
}

void exit1(){
    int i;
    for(i = 0 ;i<BANKSIZE ; i++){
        accounts[0][i] = 0;
        accounts[1][i] = 0;
        numAccounts --;
    }
    
}

