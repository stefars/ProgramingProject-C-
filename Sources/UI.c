//
// Created by hidro on 3/27/2024.
//
#include <stdio.h>
#include "../Headers/structures.h"

void printLoginInterface(){
    printf( "_*__*__*___*B_A_N_K*__*__*__*__*_\n"
            "                               \n"
            "        Welcome to BANK        \n"
            "       -----------------       \n"
            "                               \n"
            "       Please login with:      \n"
            "     login [name] [surname]    \n"
            "                               \n"
            "              or               \n"
            "         Register with:        \n"
            "   register [name] [surname]   \n"
            "                               \n"
    );
}

void printMenuInterface(const char *name,const char *surname){

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           " Hello!         \n"
           "                              \n"
           " User: %s %s                 \n"
           "                             \n"
           " Commands:                   \n"
           "    [1] Show Accounts        \n"
           "    [2] Add Account\n"
           "    [3] Edit Account\n"
           "    [4] Add Money\n"
           "    [5] Transfer Money\n"
           "    [6] Log Out\n",name,surname);
}

void printShowAccountsInterface(struct Session *Session){

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n\n"
    );
    int nr = Session ->User ->nr_accounts;
    for (int i = 0; i<nr; i++){
        if(Session->Accounts[i] == NULL){
            nr++;
            continue;}
        else
            printf("%s %c %llu\n\n",Session->Accounts[i]->IBan,*Session->Accounts[i]->coin,Session->Accounts[i]->amount);
    }
}

void printAddAccountInterfaceAsk(){

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "          \n"
           "       Generate new account?"
           "\n"
           "   Yes (Y)              Return (N)          "
           "\n\n\n");
}

void printAddAccountInterface(){

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "          \n"
           "   Creating Default Account... \n"
           "\n\n\n");
}


void printAddAccountInterfaceSuccessful(struct Account *Account){
    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "\n"
           "   Account %s %c %llu  \n"
           "\n"
           "       created successfully!    "
           "\n\n\n",Account->IBan,*Account->coin,Account->amount);
}


void printAddAccountInterfaceFailed(char code[3]){
    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "          \n"
           "   Couldn't create account. Error code %s \n"
           "\n\n\n",code);
}


void printAddMoneyIBanInterface(){

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "Insert an owned IBAN:\n\n"
           "Return to menu by typing 'back'\n\n");

}

void printAddMoneyMoneyInterface() {
    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "Insert amount:\n\n"
           "Return to menu by typing 'back'\n");

}

void printAddMoneySuccessfulInterface() {
    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "Money successfully added!\n\n");


}


void editAccountAskIBAN() {
    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "Enter an owned IBAN:\n\n\n"
           "Type 'back' to return\n");
}

void editAccountMenu(struct Account *Account) {

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "Currently editing account:\n"
           "%s\n"
           "[1] Edit Currency\n[2] Edit IBAN\n[3] Delete\n[4] Return\n\n\n",Account->IBan);

}

void editAccountCurrency(){
    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "Select a currency: \n"
           "    [E] Euro\n  [U] USD\n   [R] Ron \n"
           "\n\n\n Type 'back' to return\n");

}


void editAccountIBAN() {

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "Enter 5 capital letters ex: 'XXXXX'\n"
           "\n\n\n"
           "Type 'back' to return\n");
};