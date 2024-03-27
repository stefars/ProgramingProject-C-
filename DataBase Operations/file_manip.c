//
// Created by hidro on 3/27/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Structure Operations/struct.h"

FILE *openCsvFile(const char *filePath, const char *mode){

    if (filePath == NULL || strlen(filePath) == 0 ||
        mode == NULL || strlen(mode) == 0){
        return NULL;
    }

    FILE* file = NULL;
    file = fopen(filePath,mode);
    return file;

}


void addAccountToDb(struct Account* temp){
    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Accounts.csv", "a");

    fprintf(file_pointer,"%s,%s,%s,%lu\n",temp->IBan ,temp->id_user, temp->coin, *temp->amount);

    fclose(file_pointer);

}

void addUserToDb(struct User* temp){
    FILE *file_pointer;
    file_pointer = openCsvFile("E:\\Uni C_C++\\C\\CLion\\Programing Project\\Users.csv", "a");

    fprintf(file_pointer,"%s,%s,%s\n", temp->id, temp->name, temp->surname);

    fclose(file_pointer);


}


bool isUserInDb(char*name, char*surname){
    char *to_compare;
    char *token;
    char row[CHAR_MAX];


    to_compare = generateUserId(name, surname);
    token = (char*)malloc(sizeof(char)*(strlen(to_compare)+1));
    if (token == NULL){
        perror("Not Enough Memory\n");
        free(to_compare);
        return 0;

    }


    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Users.csv", "r");


    while(feof(file_pointer) == 0){

        fgets(row,CHAR_MAX,file_pointer);
        token = strtok(row,",");

        if (strcmp(token,to_compare) == 0){
            printf("User Found\n");
            fclose(file_pointer);
            free(to_compare);

            return 1;
        }

    }

    printf("User NOT found");
    free(to_compare);
    free(token);
    printf("%p\n",token);
    return 0;


}


bool isIbanInDb(char *IBan){

    char *token;
    char row[CHAR_MAX];

    token = (char*)malloc((sizeof(char)*15)+1);

    if (token == NULL){
        perror("Not Enough Memory\n");
        return 0;

    }

    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Accounts.csv","r");


    while(feof(file_pointer)==0){

        fgets(row,CHAR_MAX,file_pointer);
        token = strtok(row,",");

        if (strcmp(token,IBan) == 0){
            printf("Account Found\n");
            fclose(file_pointer);
            free(token);
            return 1;
        }

    }



    printf("Account Not Found\n");
    free(token);
    return 0;
}


