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
#include "../Headers/file_manip.h"

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

    Session->Accounts[acc]->amount += amount;

    modifyAccountTempFile(Session->Accounts[acc],"bluff");
    updateAccountFileOriginal();

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

int getAccountByIBAN(char *buffer,char *option,const struct Session *Session){

    fgets(buffer, 150, stdin);
    strcpy(buffer, removeDubSpaces(buffer));
    getInput(buffer,option);


    validateIBAN(option);

    if(strcmp(option,"back") == 0){
        return 100;
    }

    if(strcmp(option,"ERROR") == 0){
        return 100;
    }


    char IBAN[16];
    strcpy(IBAN,option);
    IBAN[15] = '\0';

    //Find Account Index
    for(int i = 0; i < Session->User->nr_accounts;i++){
        if(Session->Accounts[i] == NULL)
            continue;
        if(strcmp(Session->Accounts[i]->IBan,IBAN) == 0){
            return i;
        }
    }

    printf("Account not owned or does not exist.\n");
    strcpy(option,"ERROR");
    return 100;



}

void editCurrency(char *buffer,char *option,struct Account *Account){

    printf("Enter new currency. \n[E] Euro\n [U] USD\n [R] Ron \n");
    fgets(buffer, 150, stdin);
    strcpy(buffer, removeDubSpaces(buffer));
    getInput(buffer,option);

    if(strcmp(option,"ERROR")==0){
        return;
    }
    if(strcmp(option,"back")==0){
        return;
    }
    //Validate Currency
    //Just check if option == E or R or U ez

    if(!(*option == 'E' || *option == 'R' || *option == 'U')){
        strcpy(option,"ERROR");
        return;
    }

    // 4.98 R = 1 E | 1 R = 0.20 E
    // 4.46 R = 1 U | 1 R = 0.21 U
    // 1 E = 1.06 U | 1 U = 0.94 E

    if (*Account->coin == *option){
        printf("Currency already in use.");
        strcpy(option,"ERROR");

    }


    if (*Account->coin == 'R'){

        if(*option == 'E')
            Account->amount = (int)(Account->amount * 0.2);
        else
            Account->amount = (int)(Account->amount * 0.21);

    }

    if (*Account->coin == 'E'){

        if(*option == 'R')
            Account->amount = (int)(Account->amount * 4.98);
        else
            Account->amount = (int)(Account->amount * 1.06);
    }

    if(*Account->coin == 'U'){

        if(*option == 'R')
            Account->amount = (int)(Account->amount * 4.46);
        else
            Account->amount = (int)(Account->amount * 0.94);


    }

    strcpy(Account->coin,option);

    modifyAccountTempFile(Account,"bluff");
    updateAccountFileOriginal();

}

void editIBAN(char *buffer, char *option,struct Account *Account){
    printf("Enter 5 capital letters\n");

    fgets(buffer, 150, stdin);
    strcpy(buffer, removeDubSpaces(buffer));
    getInput(buffer,option);

    if(strcmp(option,"ERROR")==0){
        return;
    }

    validateEditIBAN(option);

    if(strcmp(option,"ERROR")==0){
        return;
    }

    char old_Iban[16];
    strcpy(old_Iban,Account->IBan);
    old_Iban[15] = '\0';

    for(int i = 5; i <= 9; i++){
        Account->IBan[i] = option[i-5];
    }



    modifyAccountTempFile(Account,old_Iban);
    updateAccountFileOriginal();


}


//utility?

