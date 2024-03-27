//
// Created by hidro on 3/17/2024.
//

#ifndef PROGRAMING_PROJECT_UI_H
#define PROGRAMING_PROJECT_UI_H

#include <stdio.h>

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

void printEditAccountInterface(const char *name,const char *surname){

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
           "    [6] Log Out",name,surname);
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
        create
        case 6: printf("Logging out...\n");
            exit(0);
        default: printf("Invalid choice\n");


    }



}

#endif //PROGRAMING_PROJECT_UI_H
