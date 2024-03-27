//
// Created by hidro on 3/16/2024.
//

#ifndef PROGRAMING_PROJECT_FILE_MANIP_H
#define PROGRAMING_PROJECT_FILE_MANIP_H



//MAKE SURE TO FIX FAIL CASE OPEN

FILE *openCsvFile(const char *filePath, const char *mode);



void addAccountToDb(struct Account* temp);

void addUserToDb(struct User* temp);



bool isUserInDb(char*name, char*surname);

bool isIbanInDb(char *IBan);


//TEMPORARY STORED HERE
bool isNameValid(const char *name);

#endif //PROGRAMING_PROJECT_FILE_MANIP_H
