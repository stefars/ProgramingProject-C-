//
// Created by hidro on 4/15/2024.
//

#ifndef PROGRAMING_PROJECT_MAIN_FUNCTIONS_H
#define PROGRAMING_PROJECT_MAIN_FUNCTIONS_H

char loginFunction(char **opcode, char**name, char **surname,char *buffer);

void addMoney(char *buffer, char *option, struct Session *Session);

void showAccounts(struct Session *Session,char *buffer);

void getChoice(char *buffer, char *option);

void getYesNo(char *buffer, char *option);

void editCurrency(char *buffer,char *option,struct Account *Account);

void addAccount(struct Session *Session,char *buffer);

void editIBAN(char *buffer, char *option,struct Account *Account);

void exchangeValue(unsigned long long *amount,const char coin,const char Receiver);

int getAccountByIBAN(char *buffer,char *option,const struct Session *Session);

void transferMoney(char *buffer,char *option,struct Session *Session);

#endif //PROGRAMING_PROJECT_MAIN_FUNCTIONS_H
