//
// Created by hidro on 3/16/2024.
//

#ifndef PROGRAMING_PROJECT_STRUCTURES_H
#define PROGRAMING_PROJECT_STRUCTURES_H

//Find new place for these?

#include "struct.h"

void freeUser(struct User *User);

void freeAccount(struct Account *Account);

char *generateUserId(char* name, char* surname);

char *generateIBan();

struct Account *createAccountInstance(char* id);

struct User *createUserInstance(char* name, char* surname);


#endif //PROGRAMING_PROJECT_STRUCTURES_H
