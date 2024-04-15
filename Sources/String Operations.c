//
// Created by hidro on 4/15/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *removeDubSpaces(char *input_buffer){


    short length = strlen(input_buffer),pos=0;
    char flag = '1';

    char *output_buffer = (char *)malloc((length + 1) * sizeof(char));
    if (output_buffer == NULL) {
        printf("COULD NOT ALLOCATE MEMORY\n");
        return NULL;
    }

    //Remove spaces from beginning and inside
    for(short i = 0;i < length;i++){

        if(isspace(input_buffer[i])) {

            if (flag == '0') {
                flag = '1';
                output_buffer[pos] = input_buffer[i];
                pos++;

            }
            continue;
        }


        output_buffer[pos] = input_buffer[i];
        flag = '0';
        pos++;


    }

    output_buffer[pos-1] = '\0';

    //Remove spaces at the end
    if(isspace(output_buffer[pos-2])){
        output_buffer[pos-2] = '\0';
    }


    return output_buffer;
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