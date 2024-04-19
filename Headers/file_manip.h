//
// Created by hidro on 3/16/2024.
//

#ifndef PROGRAMING_PROJECT_FILE_MANIP_H
#define PROGRAMING_PROJECT_FILE_MANIP_H



//MAKE SURE TO FIX FAIL CASE OPEN

FILE *openCsvFile(const char *filePath, const char *mode);

char* isUserInDb(const char*name,const char*surname);

bool isIbanInDb(const char *IBan);

void getRowByIban(const char *IBan, char *buffer);

void addAccountToDb(struct Account* temp);

void addUserToDb(struct User* temp);

void updateAccountFileOriginal();

void modifyAccountTempFile(const struct Account *Account,const char *old_IBAN);

void updateUsersFileOriginal();

void modifyUserTempFile(const struct User *User);

void deleteAccount(const char *IBan,struct Account **Account,struct User *User);


#endif //PROGRAMING_PROJECT_FILE_MANIP_H
