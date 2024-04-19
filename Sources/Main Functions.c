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
#include "../Headers/structures.h"

char loginFunction(char **opcode, char**name, char **surname,char *buffer){



        fgets(buffer, 150, stdin);

        printf("%s\n",buffer);

        removeDubSpaces(buffer);

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
    removeDubSpaces(buffer);
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
    removeDubSpaces(buffer);
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

    removeDubSpaces(buffer);

    getInput(buffer,option);

    if(strcmp(option,"ERROR")==0){
        return;
    }

    validateChoice(option);


}

int getAccountByIBAN(char *buffer,char *option,const struct Session *Session){


    fgets(buffer, 150, stdin);
    removeDubSpaces(buffer);
    getInput(buffer,option);


    validateIBAN(option);

    if(strcmp(option,"back") == 0){
        return -1;
    }

    if(strcmp(option,"ERROR") == 0){
        return -1;
    }



    //Find Account Index
    for(int i = 0; i < Session->User->nr_accounts;i++){
        if(Session->Accounts[i] == NULL)
            continue;
        if(strcmp(Session->Accounts[i]->IBan,option) == 0){
            return i;
        }
    }

    printf("Account not owned or does not exist.\n");
    strcpy(option,"ERROR");
    return -1;



}

void editCurrency(char *buffer,char *option,struct Account *Account){

    editAccountCurrency();

    fgets(buffer, 150, stdin);
    removeDubSpaces(buffer);
    getInput(buffer,option);

    if(strcmp(option,"ERROR")==0){
        return;
    }
    if(strcmp(option,"back")==0){
        return;
    }


    if(!(*option == 'E' || *option == 'R' || *option == 'U')){
        strcpy(option,"ERROR");
        return;
    }


    if (*Account->coin == *option){
        printf("Currency already in use.\n");
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

void exchangeValue(unsigned long long *amount,const char coin,const char Receiver){

    if (Receiver == coin){
        return;
    }

    if (coin == 'R'){

        if(Receiver == 'E')
            *amount = (int)(*amount * 0.2);
        else
            *amount = (int)(*amount * 0.21);

    }

    if (coin == 'E'){

        if(Receiver == 'R')
            *amount = (int)(*amount * 4.98);
        else
            *amount = (int)(*amount * 1.06);
    }

    if(coin == 'U'){

        if(Receiver== 'R')
            *amount = (int)(*amount * 4.46);
        else
            *amount = (int)(*amount * 0.94);

    }

}

void editIBAN(char *buffer, char *option,struct Account *Account){

    editAccountIBAN();

    fgets(buffer, 150, stdin);
    removeDubSpaces(buffer);
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


//Over flow error?
void transferMoney(char *buffer,char *option,struct Session *Session){

    printf("Input an owned Account IBAN: \n");

    int acc1 = getAccountByIBAN(buffer,option,Session);

    if(strcmp(option,"ERROR")==0){
        return;
    }

    //Acc1 Obtained
    printf("Input an Account IBAN to send money: \n");

    fgets(buffer, 150, stdin);
    removeDubSpaces(buffer);
    getInput(buffer,option);


    validateIBAN(option);


    if(strcmp(option,"back") == 0){
        return;
    }

    if(strcmp(option,"ERROR") == 0){
        return;
    }


    int acc2 = -1;
    //Find Account Index
    for(int i = 0; i < Session->User->nr_accounts;i++){
        if(Session->Accounts[i] == NULL)
            continue;
        if(strcmp(Session->Accounts[i]->IBan,option) == 0){
            acc2 = i;
        }
    }

//Cases if owned or if not owned.

    if (acc2 == -1){
        strcpy(buffer,option);
        getRowByIban(option, buffer);

        printf("%s\n",buffer);

        struct Account *temp;
        char *token;

        temp = (struct Account*)malloc(sizeof (struct Account));

        token = strtok(buffer,",");
        strcpy(temp -> IBan,token);
        token = strtok(NULL,",");
        strcpy(temp -> id_user,token);
        token = strtok(NULL,",");
        temp->coin = token;
        token = strtok(NULL,",");

        if(!strcmp(temp->coin,"0"))
        {
            temp->amount = 0;
        }
        else{

            temp->amount = validateAmount(token);

        }

        if (!strcmp(option,"ERROR")){
            printf("No IBAN found\n");
            return;
        }

        printf("Enter Amount: \n");

        fgets(buffer, 150, stdin);
        removeDubSpaces(buffer);
        getInput(buffer,option);


        if(strcmp(option,"ERROR")==0){
            return;
        }
        unsigned long long amount = validateAmount(option);

        if(strcmp(option,"back") == 0){
            return;
        }

        if(strcmp(option,"ERROR") == 0){
            return;
        }


        if(Session->Accounts[acc1]->amount - amount < 0){
            printf("Not enough money in account\n");
            strcpy(option,"ERROR");
            return;
        }
        Session->Accounts[acc1]->amount -=amount;
        exchangeValue(&amount,*Session->Accounts[acc1]->coin,*temp->coin);
        temp->amount += amount;

        modifyAccountTempFile(temp,"bluff");
        printf("Hello\n");
        updateAccountFileOriginal();
        printf("Hello\n");
        modifyAccountTempFile(Session->Accounts[acc1],"bluff");
        printf("Hello\n");
        updateAccountFileOriginal();
        printf("Hello\n");

        freeAccount(temp);

        strcpy(option,"back");
        return;
    }

    if(acc1 == acc2){
        printf("Can not transfer money to the same account\n");
        strcpy(option,"ERROR");
        return;

    }

    printf("Enter Amount: \n");

    fgets(buffer, 150, stdin);
    removeDubSpaces(buffer);
    getInput(buffer,option);

    if(strcmp(option,"ERROR")==0){
        return;
    }

    unsigned long long amount = validateAmount(option);

    if(strcmp(option,"back") == 0){
        return;
    }

    if(strcmp(option,"ERROR") == 0){
        return;
    }


    if(Session->Accounts[acc1]->amount - amount < 0){
        printf("Not enough money in account\n");
        strcpy(option,"ERROR");
        return;
    }

    Session->Accounts[acc1]->amount -=amount;

    exchangeValue(&amount,*Session->Accounts[acc1]->coin,*Session->Accounts[acc2]->coin);

    Session->Accounts[acc2]->amount += amount;


    modifyAccountTempFile(Session->Accounts[acc1],"bluff");
    updateAccountFileOriginal();
    modifyAccountTempFile(Session->Accounts[acc2],"bluff");
    updateAccountFileOriginal();

    strcpy(option,"back");
}



//utility?
