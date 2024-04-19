//
// Created by hidro on 4/19/2024.
//

#ifndef PROGRAMING_PROJECT_VALIDATORS_H
#define PROGRAMING_PROJECT_VALIDATORS_H

char validateName(const char *name);

void verifyCredentials(char *name, char *surname, char **opcode);

unsigned long long validateAmount(char *option);

void validateChoice(char *option);

void validateYesNo(char *option);

void validateIBAN(char *option);

void validateEditIBAN(char *option);


#endif //PROGRAMING_PROJECT_VALIDATORS_H
