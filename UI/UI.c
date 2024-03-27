//
// Created by hidro on 3/27/2024.
//
#include <stdio.h>
#include <stdlib.h>

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


void printShowAccountsInterface(const char *name,const char *surname){

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
    );
}


void printAddAccountInterface(){

    printf("_*__*__*___*B_A_N_K*__*__*__*__*_\n"
           "          \n"
           "   Creating Default Account... \n"
           "\n""\n""--------------------------------------");
}


void optionsMenuInterface(short choice){

    switch(choice){
        case 2: printAddAccountInterface();
        case 6: printf("Logging out...\n");
            exit(0);
        default: printf("Invalid choice\n");


    }



}