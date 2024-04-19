//
// Created by hidro on 4/19/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "../Headers/user_input.h"


#define MAX_NAME 50

char validateName(const char *name){
    int i = 0;
    while(*(i+name)) {

        //Check if char is a letter
        if ((*(i+name)<'A')||(*(i+name)>'z')||(((*(i+name)>'Z') && (*(i+name)<'a')))){
            return 0;
        }
        i++;
    }
    return 1;

}

void verifyCredentials(char *name, char *surname, char **opcode){

    if(strcmp(*opcode,"exit") == 0){
        return;
    }

    if ((strcmp(*opcode,"login") != 0) && (strcmp(*opcode,"register") != 0)){
        printf("Invalid command\n");
        *opcode = NULL;
        return;

    }

    if(strlen(name) > MAX_NAME  || strlen(surname) > MAX_NAME){
        printf("Name or surname too long\n");
        sleep(1);
        *opcode = NULL;
        return;
    }

    if(!(validateName(name) && validateName(surname))){
        printf("Name or surname contains symbols, numbers, or non-recognized characters\n");
        sleep(1);
        *opcode = NULL;
        return;
    }



}

unsigned long long validateAmount(char *option){

    if(strcmp(option,"back")==0)
        return 0;



    unsigned long long int amount = 0;
    short length = strlen(option);

    if(strcmp(option,"0")==0){
        printf("Can not add nothing.");
        sleep(1);
        return 0;
    }

    if(length > 19){
        printf("Invalid amount. I'm sure you don't have that much.");
        sleep(1);
        strcpy(option,"ERROR");
        return 0;

    }

    for (int i = 0; i < length; i++){
        if(!isdigit(option[i])){
            printf("Input needs to be a positive integer.\n");
            sleep(1);
            strcpy(option,"ERROR");
            return 0;
        }

        amount = amount * 10 + (option[i] - 48);

    }


    return amount;

}

void validateChoice(char *option){

    short length = strlen(option);

    char choices[6] = "123456";

    if(length != 1){
        printf("Invalid choice\n");
        strcpy(option,"ERROR");
        return;
    }
    int i = 0;
    while(choices[i]!='\0'){
        if(*option == choices[i])
            return;
        i++;
    }

    strcpy(option,"ERROR");
    printf("Please select an option from 1 to %d\n",strlen(choices)-1);
}

void validateYesNo(char *option){

    if(!strcmp(option,"Y") || !strcmp(option,"y")){
        strcpy(option,"Y");
        return;
    }

    if(!strcmp(option,"N") || !strcmp(option,"n")){
        strcpy(option,"N");
        return;
    }

    strcpy(option,"ERROR");

    printf("Invalid choice\n");

}

void validateIBAN(char *option){

    short length = strlen(option);

    if(strcmp(option,"back")==0)
        return;

    if ((length != 15) || !((*option == '1') || (*option == '0'))) {
        printf("Invalid IBAN\n");
        strcpy(option,"ERROR");
        return;

    }

    for(int i = 1; i <= 9; i++){
        if(islower(option[i])){
            printf("Invalid IBAN\n");
            strcpy(option,"ERROR");
            return;
        }

    }

    int sum = 0;

    for(int i = 10; i <= 14; i++){

        if(!isdigit(option[i])){
            printf("Invalid IBAN\n");
            strcpy(option,"ERROR");
            return;
        }

        sum += option[i] - 48;

    }

    if(!((*option == '1' && sum <= 25) || (*option == '0' && sum > 25))){
        printf("Invalid IBAN\n");
        strcpy(option,"ERROR");
        return;
    }

}

void validateEditIBAN(char *option){

    if (strlen(option) != 5){
        strcpy(option,"ERROR");
        return;
    }

    for(int i = 0; i < 5; i++){

        if(option[i] < 'A' || option[i] > 'Z'){
            strcpy(option,"ERROR");
            printf("Invalid format\n");
            return;
        }

    }


}