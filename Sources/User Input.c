//
// Created by hidro on 4/15/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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