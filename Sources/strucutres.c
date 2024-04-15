//
// Created by hidro on 3/27/2024.
//
#include <stdlib.h>
#include <string.h>
#include "../Headers/struct.h"
#include <stdio.h>
#include "../Headers/generate.h"
#include "../Headers/file_manip.h"



void freeUser(struct User *User){
    free(User->surname);
    free(User->name);
    free(User->id);
    free(User);

}

void freeAccount(struct Account *Account){
    free(Account->IBan);
    free(Account->id_user);
    free(Account->coin);
    free(Account);

}



struct Account *createAccountInstance(const char* id){

    struct Account *temp;

    temp = (struct Account*)malloc(sizeof(struct Account));

    if(temp == NULL){
        printf("Not Enough Memory");
        exit(0);
    }

    temp->IBan = generateIBan();
    temp->id_user = (char*)malloc(sizeof(char)*strlen(id));
    temp->coin = (char*)malloc(sizeof(char));

    strcpy(temp->id_user,id);
    strcpy(temp->coin,"R");
    temp->amount = 0;

    return temp;
}

struct User *createUserInstance(const char* name,const char* surname){

    struct User *temp;

    temp = (struct User*)malloc(sizeof(struct User));

    temp->id = generateUserId(name, surname);
    temp->name = (char*)malloc(sizeof(char)*strlen(name)+1);
    temp->surname = (char*)malloc(sizeof(char)*strlen(surname)+1);

    strcpy(temp->name,name);
    strcpy(temp->surname,surname);
    temp->nr_accounts = 1;


    return temp;
}

void addAccountToSession(struct Account *temp,struct Session *Session){

    Session->Accounts = (struct Account**) realloc(Session->Accounts,
            sizeof(struct Account*)*Session->User->nr_accounts);

    if (Session->Accounts == NULL){
        printf("FATAL ERROR, QUITTING");
        exit(0);

    }


    Session->Accounts[Session->User->nr_accounts-1] = temp;

}

void createUserAccount(const char *user_id){
    struct Account *New_Account;

    New_Account = createAccountInstance(user_id);

    addAccountToDb(New_Account);

    freeAccount(New_Account);
    //Free Amount also?
}  //delete?

void createNewUser(char* name, char* surname){

    struct User *New_User;
    struct Account *New_Account;

    //Generate new instances
    New_User = createUserInstance(name, surname);

    while(1){
        New_Account = createAccountInstance(New_User->id);
        if(isIbanInDb(New_Account->IBan)){
            freeAccount(New_Account);
            continue;
        }
        break;
    }




    //Update files
    addUserToDb(New_User);
    addAccountToDb(New_Account);

    freeAccount(New_Account);
    freeUser(New_User);

}

