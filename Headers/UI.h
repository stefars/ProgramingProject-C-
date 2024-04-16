//
// Created by hidro on 3/17/2024.
//

#ifndef PROGRAMING_PROJECT_UI_H
#define PROGRAMING_PROJECT_UI_H



void printLoginInterface();

void printMenuInterface(const char *name,const char *surname);

void printShowAccountsInterface(struct Session *Session);

void printAddAccountInterfaceAsk();

void printAddAccountInterface();

void printAddAccountInterfaceSuccessful(struct Account *Account);

void printAddAccountInterfaceFailed(char code[3]);

void printAddMoneySuccessfulInterface();

void printAddMoneyMoneyInterface();

void printAddMoneyIBanInterface();




#endif //PROGRAMING_PROJECT_UI_H
