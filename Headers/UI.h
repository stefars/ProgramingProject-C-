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

void printAskAmount();

void printAddMoneyIBanInterface();

void printAskOwnedIBAN();

void printEditAccountMenu(struct Account *Account);

void printEditAccountCurrency();

void printEditAccountIBAN();

void printAskReceiverIban();




#endif //PROGRAMING_PROJECT_UI_H
