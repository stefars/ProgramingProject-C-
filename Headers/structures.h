//
// Created by hidro on 3/16/2024.
//

#ifndef PROGRAMING_PROJECT_STRUCTURES_H
#define PROGRAMING_PROJECT_STRUCTURES_H



#include "struct.h"

void freeUser(struct User *User);

void freeAccount(struct Account *Account);

struct Account *createAccountInstance(const char* id);

struct User *createUserInstance(char* name, char* surname);

void addAccountToSession(struct Account *temp,struct Session *Session);

void createUserAccount(const char *user_id);

void createNewUser(char* name, char* surname);

#endif //PROGRAMING_PROJECT_STRUCTURES_H
