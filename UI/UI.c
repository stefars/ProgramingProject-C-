//
// Created by hidro on 3/27/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "../Structure Operations/structures.h"

void printLoginInterface(){
    printf( "_*__*__*___*B_A_N_K*__*__*__*__*_\n"
            "{                               }\n"
            "}        Welcome to BANK        {\n"
            "{       -----------------       }\n"
            "{                               }\n"
            "}       Please login with:      {\n"
            "{     login [name] [surname]    }\n"
            "{                               }\n"
            "{              or               }\n"
            "}         Register with:        {\n"
            "{   register [name] [surname]   }\n"
            "{                               }\n"
            "---------------------------------\n"
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
        printf("%s %c %lu\n\n",Session->Accounts[i]->IBan,*Session->Accounts[i]->coin,Session->Accounts[i]->amount);
    }
}

void printAddAccountInterface(){

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "          \n"
           "   Creating Default Account... \n"
           "\n""\n""--------------------------------------\n");
}


void printAddAccountInterfaceSuccessful(){
    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "          \n"
           "   Account created successfully! \n"
           "\n""\n""--------------------------------------\n");
}


void printAddAccountInterfaceFailed(char code[3]){
    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "          \n"
           "   Couldn't create account. Error code %s \n"
           "\n""\n""--------------------------------------\n",code);
}



