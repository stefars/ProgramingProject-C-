//
// Created by hidro on 4/2/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/file_manip.h"
#include "../Headers/struct.h"
#include "../Headers/structures.h"




struct Account **fetchAccountsData(const char* user_id,int nr_accounts){
    char *row;
    char *token;
    char buffer[200];
    int index = 0;
    struct Account **Accounts;



    Accounts = (struct Account**)malloc(sizeof(struct Account*)*nr_accounts);


    FILE* file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Accounts.csv","r");



    while(fgets(buffer,200,file_pointer)!=NULL){

        if (nr_accounts == 0) {

            break;
        }


        row = (char*)malloc(sizeof(char)*strlen(buffer));


        //Fail case

        strcpy(row,buffer);

        if(*row == '\n'){
            free(row);
            continue;

        }
        token = strtok(buffer,",");
        token = strtok(NULL,",");



        if (strcmp(token,user_id)==0){

            struct Account *temp;

            //Make new function?
            temp = createAccountInstance(user_id);

            token = strtok(row,",");
            strcpy(temp -> IBan,token);

            token = strtok(NULL,",");
            strcpy(temp -> id_user,token);

            token = strtok(NULL,",");
            strcpy(temp -> coin,token);


            token = strtok(NULL,",");

            //String to Integer
            int i = 0;
            unsigned long long amount = 0;
            while(token[i] != '\n'){
                amount = amount * 10 + (token[i] - 48);
                i++;
            }

            temp -> amount = amount;

            Accounts[index] = temp;

            index++;
            nr_accounts--;




        }

        free(row);
    }

    token = NULL;
    printf("One day?\n");
    fclose(file_pointer);
    return Accounts;

}

struct Session *fetchUserData(char* name,char* surname){
    
    struct Session *Session;
    char *row;
    char *token;
    int nr_accounts;
    row = isUserInDb(name,surname);

    if (row == NULL){
        return NULL;
    }

    //Fail case

    Session = (struct Session*)malloc(sizeof(struct Session));

    //Fail case


    //GET USER INFO
    token = strtok(row,",");
    for(int i = 0; i <= 2; i++){
        token = strtok(NULL,",");
    }

    nr_accounts = strtol(token,NULL,10);
    struct User *temp;
    temp = createUserInstance(name,surname);
    temp -> nr_accounts = nr_accounts;



    Session -> User = temp;



    //GET ACCOUNTS INFO

    Session->Accounts = fetchAccountsData(temp->id, temp->nr_accounts);


    return Session;

}

