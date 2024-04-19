//
// Created by hidro on 4/15/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>



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
            sleep(1);
            *opcode = NULL;
            return;
        }
        return;

    }

    if(arguments != 3){

        *opcode = NULL;

        if(arguments < 3){
            printf("Not enough arguments, 3 needed.\n");
            sleep(1);
            return;
        }

        printf("Too many arguments,only 3 needed.\n");
        sleep(1);
        return;

    }


    *name = strtok(NULL," ");

    *surname = strtok(NULL,"\n");



}

void getInput(char *buffer,char *option){

    // Used for: menu choice, amount to transfer (Input owned IBAN, Input Amount), transfer between accounts, edit
    // (Input owned IBAN, Input other IBAN, Input Amount)


    int arguments = 1,buffer_length;

    strcpy(option,"ERROR");

    buffer_length = strlen(buffer);

    if (buffer_length==0){
        printf("No input detected\n");
        sleep(1);
        return;
    }

    for (int i = 0; i < buffer_length; i++){

        if (isspace(*(buffer+i)))
            arguments++;
    }


    if(arguments != 1){

        if(arguments < 1){
            printf("Not enough arguments, 1 needed.\n");
            sleep(1);
            return;
        }

        printf("Too many arguments,only 1 needed.\n");
        sleep(1);
        return;
    }

    strcpy(option,buffer);


}


