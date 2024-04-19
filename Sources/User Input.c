//
// Created by hidro on 4/15/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/String Operations.h"

#define MAX_NAME 50

void getCredentials(char *input_buffer,char **name, char **surname, char **opcode){

    int arguments = 1,buffer_length;

    buffer_length = strlen(input_buffer);

    for (int i = 0; i < buffer_length; i++){

        if (*(input_buffer+i) == ' ')
            arguments++;

    }

    *opcode = strtok(input_buffer," ");

    if(strcmp(*opcode,"exit")==0){
        if (arguments > 1){
            printf("Exit command requires no arguments.\n");
            *opcode = NULL;
            return;
        }
        return;

    }

    if(arguments != 3){

        *opcode = NULL;

        if(arguments < 3){
            printf("Not enough arguments, 3 needed.\n");
            return;
        }

        printf("Too many arguments,only 3 needed.\n");
        return;

    }


    *name = strtok(NULL," ");

    *surname = strtok(NULL,"\n");



}

void getInput(char *buffer,char *option){

    // Used for: menu choice, amount to transfer (Input owned IBAN, Input Amount), transfer between accounts
    // (Input owned IBAN, Input other IBAN, Input Amount)
    // Probably for edit also?

    //Should be only one string (if it has multiple it's invalid, request again.

    int arguments = 1,buffer_length;

    strcpy(option,"ERROR");

    buffer_length = strlen(buffer);

    if (buffer_length==0){
        printf("No input detected\n");
        return;
    }

    for (int i = 0; i < buffer_length; i++){

        if (isspace(*(buffer+i)))
            arguments++;
    }


    if(arguments != 1){

        if(arguments < 1){
            printf("Not enough arguments, 1 needed.\n");
            return;
        }

        printf("Too many arguments,only 1 needed.\n");
        return;
    }

    strcpy(option,buffer);


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
        *opcode = NULL;
        return;
    }

    if(!(isNameValid(name) && isNameValid(surname))){
        printf("Name or surname contains symbols, numbers, or non-recognized characters\n");
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
        return 0;
    }

    if(length > 19){
        printf("Invalid amount. I'm sure you don't have that much.");
        strcpy(option,"ERROR");
        return 0;

    }

    for (int i = 0; i < length; i++){
        if(!isdigit(option[i])){
            printf("Input needs to be a positive integer.\n");
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

    printf("Validated\n");

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



//UTILITY

