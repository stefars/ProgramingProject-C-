//
// Created by hidro on 3/27/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/structures_operations.h"
#include "../Headers/generate.h"


FILE *openCsvFile(const char *filePath, const char *mode){

    if (filePath == NULL || strlen(filePath) == 0 ||
        mode == NULL || strlen(mode) == 0){
        return NULL;
    }

    FILE* file = NULL;
    file = fopen(filePath,mode);

    if(file == NULL){
        fopen(filePath,"w");
        fclose(file);
    }

    file = fopen(filePath,mode);

    return file;

}

char *isUserInDb(const char *name,const char *surname){
    char *to_compare;
    char *token;
    char *row;
    char buffer[CHAR_MAX];

    to_compare = generateUserId(name,surname);
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

bool isIbanInDb(const char *IBan){

    char *token;
    char row[200];

    token = (char*)malloc((sizeof(char)*15)+1);

    if (token == NULL){
        perror("Not Enough Memory\n");
        return 0;

    }

    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Accounts.csv","r");


    while(feof(file_pointer)==0){

        fgets(row,200,file_pointer);
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

void getRowByIban(const char *IBan, char *buffer){

    char *token;
    char row[200];

    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Accounts.csv","r");

    while(fgets(row,200,file_pointer)!=NULL){
        strcpy(buffer,row);
        token = strtok(row,",");

        if (strcmp(token,IBan) == 0){
            printf("Account Found\n");
            fclose(file_pointer);
            return;
        }

    }

    strcpy(buffer,"ERROR");
    printf("Iban not in Data Base");
}

void addAccountToDb(struct Account* temp){
    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Accounts.csv", "a");

    fprintf(file_pointer,"%s,%s,%s,%llu\n",temp->IBan ,temp->id_user, temp->coin, temp->amount);

    fclose(file_pointer);

}

void addUserToDb(struct User* temp){
    FILE *file_pointer;
    file_pointer = openCsvFile("..\\Data Base\\Users.csv", "a");

    fprintf(file_pointer,"%s,%s,%s,%d\n", temp->id, temp->name, temp->surname,temp->nr_accounts);

    fclose(file_pointer);

}

void updateAccountFileOriginal(){
    FILE* file_input;
    FILE* file_output;
    char buffer[100];

    file_input = openCsvFile("../Data Base/Accounts.csv","w");

    file_output = openCsvFile("../Data Base/Accounts_Temp.csv","r");

    while (fgets(buffer, sizeof buffer, file_output) != NULL)
    {

        fputs(buffer,file_input);
    }

    if (feof(file_output))
    {
        fclose(file_input);
        fclose(file_output);
    }

}

void updateUsersFileOriginal(){
    FILE* file_input;
    FILE* file_output;
    char buffer[100];

    file_input = openCsvFile("../Data Base/Users.csv","w");

    file_output = openCsvFile("../Data Base/Users_Temp.csv","r");

    while (fgets(buffer, sizeof buffer, file_output) != NULL)
    {

        fputs(buffer,file_input);
    }

    if (feof(file_output))
    {
        fclose(file_input);
        fclose(file_output);

    }



}

void modifyAccountTempFile(const struct Account *Account,const char *old_IBAN){

    FILE* file_input;
    FILE* file_output;
    char buffer[100];
    char row[100];
    char *token;
    printf("Dada\n");
    file_input = openCsvFile("../Data Base/Accounts.csv","r");
    file_output = openCsvFile("../Data Base/Accounts_Temp.csv","w");
    printf("Dada\n");

    while (fgets(row, sizeof buffer, file_input) != NULL)
    {
        printf("Dada\n");
        strcpy(buffer,row);
        token = strtok(buffer,",");
        printf("Dada\n");

        //CONSTRUCT THE STRING
        if(!strcmp(token,Account->IBan)||!strcmp(token,old_IBAN)){

            sprintf(row,"%s,%s,%c,%llu\n",Account->IBan,Account->id_user,*Account->coin,Account->amount);
            printf("%s\n",Account->id_user);
        }

        fputs(row,file_output);
    }

    if (feof(file_input))
    {
        fclose(file_input);
        fclose(file_output);
        printf("Completed?\n");
    }
    else
    {
        fclose(file_input);
        fclose(file_output);
        printf("Error?\n");
    }

}

void modifyUserTempFile(const struct User *User){

    FILE* file_input;
    FILE* file_output;
    char buffer[100];
    char row[100];
    char *token;

    file_input = openCsvFile("../Data Base/Users.csv","r");

    file_output = openCsvFile("../Data Base/Users_Temp.csv","w");


    while (fgets(row, sizeof buffer, file_input) != NULL)
    {
        strcpy(buffer,row);
        token = strtok(buffer,",");

        //CONSTRUCT THE STRING
        if(!strcmp(token,User->id)){

            sprintf(row,"%s,%s,%s,%d\n",User->id,User->name,User->surname,User->nr_accounts);
        }

        fputs(row,file_output);
    }

    if (feof(file_input))
    {
        fclose(file_input);
        fclose(file_output);
        printf("Completed?\n");
    }
    else
    {
        fclose(file_input);
        fclose(file_output);
        printf("Error?\n");
    }



}

void deleteAccount(const char *IBan,struct Account **Account,struct User *User){
    FILE* file_input;
    FILE* file_output;
    char buffer[100];
    char row[100];
    char *token;

    file_input = openCsvFile("../Data Base/Accounts.csv","r");

    file_output = openCsvFile("../Data Base/Accounts_Temp.csv","w");


    while (fgets(row, sizeof buffer, file_input) != NULL)
    {
        strcpy(buffer,row);
        token = strtok(buffer,",");

        //Skip
        if(!strcmp(token,IBan)){
          continue;
        }

        fputs(row,file_output);
    }

    if (feof(file_input))
    {
        fclose(file_input);
        fclose(file_output);
        printf("Completed?\n");
    }
    else
    {
        fclose(file_input);
        fclose(file_output);
        printf("Error?\n");
    }

    User->nr_accounts--;

    modifyUserTempFile(User);
    updateUsersFileOriginal();
    updateAccountFileOriginal();


    //MAY CAUSE ERRORS
    freeAccount(*Account);

    printf("%p\n",*Account);
    *Account = NULL;
    printf("%p\n",*Account);


}




