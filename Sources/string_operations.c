//
// Created by hidro on 4/15/2024.
//

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



