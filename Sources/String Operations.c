//
// Created by hidro on 4/15/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeDubSpaces(char *input_buffer){


    short length = strlen(input_buffer);
    short pos = 0;
    char prev_char = ' ';


    for (short i = 0; i < length; i++) {
        char currentChar = input_buffer[i];

        if (isspace(currentChar)) {
            if (!isspace(prev_char)) {
                input_buffer[pos++] = ' ';
            }
        } else {
            input_buffer[pos++] = currentChar;
        }

        prev_char = currentChar;
    }

    // Null-terminate the output string
    input_buffer[pos] = '\0';

    // Trim trailing spaces
    while (pos > 0 && isspace(input_buffer[pos - 1])) {
        pos--;
    }

    input_buffer[pos] = '\0';

}

char isNameValid(const char *name){
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