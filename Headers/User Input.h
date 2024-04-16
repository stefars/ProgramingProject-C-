//
// Created by hidro on 4/15/2024.
//

#ifndef PROGRAMING_PROJECT_USER_INPUT_H
#define PROGRAMING_PROJECT_USER_INPUT_H


void getCredentials(char *input_buffer,char **name, char **surname, char **opcode);

void verifyCredentials(char *name, char *surname, char **opcode);

void getInput(char *buffer,char *option);

unsigned long long validateAmount(char *option);

void validateChoice(char *option);

void validateIBAN(char *option);

void validateEditIBAN(char *option);

#endif //PROGRAMING_PROJECT_USER_INPUT_H
