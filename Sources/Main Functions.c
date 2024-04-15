//
// Created by hidro on 4/15/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/String Operations.h"
#include "../Headers/User Input.h"

char loginFunction(char **opcode, char**name, char **surname,char *buffer){



        fgets(buffer, 150, stdin);

        printf("%s\n",buffer);

        strcpy(buffer, removeDubSpaces(buffer));

        getCredentials(buffer,name,surname,opcode);
        if(*opcode == NULL){
            printf("Failed argument pass \n");
            return '9';
        }

        verifyCredentials(*name,*surname,opcode);
        if(*opcode == NULL){
            printf("Failed validation pass\n");
            return '9';
        }


        if(strcmp(*opcode,"exit")==0) {
            *name = NULL;
            *surname = NULL;
            return '0';
        }

        if(strcmp(*opcode,"login")==0){
            return '1';
        }

        if(strcmp(*opcode,"register")==0) {
            return '2';
        }


        printf("Unknown ERROR\n");
        return '9';

}