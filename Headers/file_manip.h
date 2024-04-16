//
// Created by hidro on 3/16/2024.
//

#ifndef PROGRAMING_PROJECT_FILE_MANIP_H
#define PROGRAMING_PROJECT_FILE_MANIP_H



//MAKE SURE TO FIX FAIL CASE OPEN

FILE *openCsvFile(const char *filePath, const char *mode);

// NO SIMULTANOUS SESSIONS EZ PZ

FILE *findUserInDb(const char *name, const char *surname);

void updateUserToDb(const char *name, const char *surname, const char *to_update);

char* isUserInDb(const char*name,const char*surname);

bool isIbanInDb(const char *IBan);

void addSessionToDb(struct Session* temp);

void addAccountToDb(struct Account* temp);

void addUserToDb(struct User* temp);






//TEMPORARY STORED HERE

void updateAccountFileOriginal();
void modifyAccountTempFile(const struct Account *Account,const char *old_IBAN);

void updateUsersFileOriginal();
void modifyUserTempFile(const struct User *User);
void deleteAccount(const char *IBan,struct Account **Account,struct User *User);


#endif //PROGRAMING_PROJECT_FILE_MANIP_H
