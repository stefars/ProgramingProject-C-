//
// Created by hidro on 3/27/2024.
//

#ifndef PROGRAMING_PROJECT_STRUCT_H
#define PROGRAMING_PROJECT_STRUCT_H
struct User {
    char* id;
    char* name;
    char* surname;
    int nr_accounts;   //REMEMBER THIS
};

struct Account {
    char* IBan;
    char* id_user;
    char* coin;
    unsigned long long amount;

};

struct Session {
    struct User *User;
    struct Account **Accounts;



};


#endif //PROGRAMING_PROJECT_STRUCT_H
