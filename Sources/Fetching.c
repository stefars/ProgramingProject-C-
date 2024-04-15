//
// Created by hidro on 4/2/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/file_manip.h"
#include "../Headers/struct.h"
#include "../Headers/structures.h"




struct Account **fetchAccountsData(const char* user_id,int nr_accounts){
    char *row;
    char *token;
    char buffer[CHAR_MAX];
    int index = 0;
    struct Account **Accounts;

    Accounts = (struct Account**)malloc(sizeof(struct Account*)*nr_accounts);


    FILE* file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Accounts.csv","r");



    while(feof(file_pointer)==0){

        if (nr_accounts == 0)
            break;

        fgets(buffer,CHAR_MAX,file_pointer);

        row = (char*)malloc(sizeof(char)*strlen(buffer));

        //Fail case

        strcpy(row,buffer);

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
            temp -> coin = token;

            token = strtok(NULL,",");
            temp -> amount = strtol(token,NULL,10);

            Accounts[index] = temp;

            index++;
            nr_accounts--;


        }


    }
    token = NULL;
    free(token);
    free(row);
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

