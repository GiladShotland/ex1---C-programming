#include<stdio.h>
#include<stdbool.h>
#include"myBank.h"
int main(){
    int ans1;
    double ans2;
    char decision;
    int account;
    while(decision != 'E'){
        printf("\n");
        printf("Please choose a transaction type: \n");
        printf(" O-Open Account\n");    
        printf(" B-Balance Inquiry\n");
        printf(" D-Deposit\n");
        printf(" W-Withdrawal\n");
        printf(" C-Close Account\n");
        printf(" I-Interest\n");
        printf(" P-Print\n");
        printf(" E-Exit\n");
        scanf(" %c",&decision);
        switch(decision){
            case 'O':
                    ans1 = openAccount();
                    if(!ans1){
                        printf("There is no room in the bank");
                    }
                    else{
                        switch(ans1){
                            case -1:
                                printf("Failed to read the amount");
                                break;
                            case -2:
                                printf("Invalid amount");
                                break;
                            default:
                                printf("New account number is: %d" ,ans1);
                                break;
                        }
                    }
                    printf("\n");
                    break;

            case 'B':
                    printf("Please enter account number: ");
                    if(scanf(" %d",&account) == 0){
                        printf("Failed to read the account number");
                        }
                    else{
                        ans2 = balanceInquiry(account);
                        switch((int)ans2){
                            case -1:
                                printf("Invalid account number");
                                break;
                            case 0:
                                printf("This account is closed");
                                break;
                            default:
                                printf("The balance for account %d is: %.2lf", account,ans2);
                                break;
                        }
                    }
                    printf("\n");
                    break;   
            case 'D':
                    printf("Please enter account number: ");
                    if(scanf(" %d",&account) == 0){
                        printf("Failed to read the account number");}
                    else{
                        ans2 = deposit(account);
                        switch((int)ans2){
                            case 0:
                                printf("This account is closed");
                                break;
                            case -1:
                                printf("Failed to read the amount");
                                break;
                            case -2:
                                printf("Invalid account number");
                                break;
                            case -3:
                                printf("Cannot deposit a negative amount");
                                break;
                            default:
                                printf("The new balance is: %.2lf",ans2);
                                break;

                        }
                    }
                    printf("\n");
                    break;
            case 'W':
                    printf("Please enter account number: ");
                    if(scanf(" %d",&account) == 0){print("Failed to read the account number");}
                    else{
                        ans2 = withdrawal(account);
                        if(!ans2){printf("This account is closed");}
                        else{
                            switch((int)ans2){
                                case -1 :
                                    printf("Failed to read the amount");
                                    break;
                                case -2:
                                    printf("Cannot withdraw more than the balance");
                                    break;
                                case -3:
                                    printf("Invalid account number");
                                    break;
                                default:
                                    printf("The new balance is: %.2lf", ans2);
                                    break;
                            }

                        }
                    }
                    printf("\n");
                    break;


            case 'C':
                    printf("Please enter account number: ");
                    if(scanf(" %d",&account) == 0){printf("Failed to read the account number");}
                    else{
                        ans1 = closeAccount(account);
                        if(!ans1){printf("This account is already closed");}
                        else{printf("Closed account number %d ",account);}
                    }
                    printf("\n");
                    break;


            case 'I':
                    ans1 = interest();
                    switch(ans1){
                        case 0:
                            printf("Failed to read the interest rate");
                            break;
                        case -1:
                            printf("Invalid interest rate");
                            break;
                        default:
                            break;
                    }
                    printf("\n");
                    break;

            case 'P':
                     print();
                     break;

            case 'E':
                    exit1();
                    break;
            default:
                    printf("invalid transaction type\n");
        }
    }
}