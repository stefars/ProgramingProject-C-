//
// Created by hidro on 4/15/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/String Operations.h"
#include "../Headers/User Input.h"
#include "../Headers/struct.h"
#include "../Headers/UI.h"

char loginFunction(char **opcode, char**name, char **surname,char *buffer){



        fgets(buffer, 150, stdin);

        printf("%s\n",buffer);

        strcpy(buffer, removeDubSpaces(buffer));

        getCredentials(buffer,name,surname,opcode);
        if(*opcode == NULL){
            printf("Failed argument pass \n");
            return '9';
        }

        verifyCredentials(*name,*surname,opcode);
        if(*opcode == NULL){
            printf("Failed validation pass\n");
            return '9';
        }


        if(strcmp(*opcode,"exit")==0) {
            *name = NULL;
            *surname = NULL;
            return '0';
        }

        if(strcmp(*opcode,"login")==0){
            return '1';
        }

        if(strcmp(*opcode,"register")==0) {
            return '2';
        }


        printf("Unknown ERROR\n");
        return '9';

}

void addMoneyFunction(char *buffer,char *option,struct Session *Session){

    printAddMoneyIBanInterface();

    unsigned long long amount;
    //GET IBAN
    fgets(buffer, 150, stdin);
    strcpy(buffer, removeDubSpaces(buffer));
    getInput(buffer,option);

    //Create condition for return
    validateIBAN(option);

    if(strcmp(option,"back") == 0){
        return;
    }

    if(strcmp(option,"ERROR") == 0){
        return;
    }

    int acc = -1;
    char IBAN[15];
    strcpy(IBAN,option);

    //Find Account Index
    for(int i = 0; i < Session->User->nr_accounts;i++){
        if(strcmp(Session->Accounts[i]->IBan,IBAN) == 0){
            acc = i;
            break;
        }
    }

    if (acc == -1){
        printf("Account not owned or does not exist.\n");
        strcpy(option,"ERROR");
        return;

    }

    printAddMoneyMoneyInterface();


    // GET AMOUNT
    fgets(buffer, 150, stdin);
    strcpy(buffer, removeDubSpaces(buffer));
    getInput(buffer,option);

    if(strcmp(option,"ERROR")==0){
        return;
    }

    amount = validateAmount(option);

    if(strcmp(option,"back") == 0){
        return;
    }

    if(amount == 0){
        strcpy(option,"ERROR");
        return;

    }

    Session->Accounts[acc]->amount = amount;

    printAddMoneySuccessfulInterface();
}

void getChoiceFunction(char *buffer,char *option){

    fgets(buffer, 150, stdin);

    strcpy(buffer, removeDubSpaces(buffer));

    getInput(buffer,option);

    if(strcmp(option,"ERROR")==0){
        return;
    }

    validateChoice(option);


}