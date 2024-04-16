//
// Created by hidro on 3/27/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/structures.h"
#include "../Headers/generate.h"

FILE *openCsvFile(const char *filePath, const char *mode){

    if (filePath == NULL || strlen(filePath) == 0 ||
        mode == NULL || strlen(mode) == 0){
        return NULL;
    }

    FILE* file = NULL;
    file = fopen(filePath,mode);
    return file;

}



char *isUserInDb(const char *name,const char *surname){
    char *to_compare;
    char *token;
    char *row;
    char buffer[CHAR_MAX];

    to_compare = generateUserId(name, surname);
    token = (char*)malloc(sizeof(char)*(strlen(to_compare)+1));

    if (token == NULL){
        perror("Not Enough Memory\n");
        free(to_compare);
        return 0;
    }

    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Users.csv", "r");


    while(feof(file_pointer) == 0){

        fgets(buffer,CHAR_MAX,file_pointer);

        row = (char*)malloc(sizeof(char)*strlen(buffer));
        strcpy(row,buffer);

        token = strtok(buffer,",");

        if (strcmp(token,to_compare) == 0){

            to_compare = NULL;
            free(to_compare);
            fclose(file_pointer);

            return row;
        }

    }

    to_compare = NULL;
    token = NULL;
    row  = NULL;

    free(to_compare);
    free(token);
    free(row);

    fclose(file_pointer);
    return NULL;

}


FILE *findUserInDb(const char *name, const char *surname){

    char *to_compare;
    char *token;
    char *row;
    char buffer[CHAR_MAX];

    to_compare = generateUserId(name, surname);
    token = (char*)malloc(sizeof(char)*(strlen(to_compare)+1));

    if (token == NULL){
        perror("Not Enough Memory\n");
        free(to_compare);
        return 0;
    }

    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Users.csv", "r");


    while(feof(file_pointer) == 0){

        fgets(buffer,CHAR_MAX,file_pointer);

        row = (char*)malloc(sizeof(char)*strlen(buffer));
        strcpy(row,buffer);

        token = strtok(buffer,",");

        if (strcmp(token,to_compare) == 0){

            to_compare = NULL;
            free(to_compare);
            return file_pointer;
        }

    }

    to_compare = NULL;
    token = NULL;
    row  = NULL;

    free(to_compare);
    free(token);
    free(row);

    fclose(file_pointer);
    return NULL;


}

bool isIbanInDb(const char *IBan){

    char *token;
    char row[CHAR_MAX];

    token = (char*)malloc((sizeof(char)*15)+1);

    if (token == NULL){
        perror("Not Enough Memory\n");
        return 0;

    }

    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Accounts.csv","r");


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


    token = NULL;
    free(token);
    return 0;
}


void updateSessionToDb(struct Session* temp){






}

void updateUserToDb(const char *name, const char *surname, const char *to_update){

    char *row;
    char buffer[CHAR_MAX];

    row = isUserInDb(name,surname);

    if (row == NULL) {
        printf("Error while Updating User");
        return;
    }

    if (strcmp(row,to_update)==0){
        printf("Nothing to update");
        return;
    }

    printf("Updating user");

    FILE *file_pointer;

    file_pointer = findUserInDb(name,surname);

    fgets(buffer,CHAR_MAX,file_pointer);
    printf("%s",buffer);






}


void addAccountToDb(struct Account* temp){
    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Accounts.csv", "a");

    fprintf(file_pointer,"%s,%s,%s,%lu\n",temp->IBan ,temp->id_user, temp->coin, temp->amount);

    fclose(file_pointer);

}

void addUserToDb(struct User* temp){
    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Users.csv", "a");

    fprintf(file_pointer,"%s,%s,%s,%d\n", temp->id, temp->name, temp->surname,temp->nr_accounts);

    fclose(file_pointer);

}





