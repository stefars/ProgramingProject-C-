#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Structure Operations/structures.h"
#include "DataBase Operations/file_manip.h"
#include <time.h>
#include "UI/UI.h"


void createNewUser(char* name, char* surname){

    struct User *New_User;
    struct Account *New_Account;

    //Generate new instances
    New_User = createUserInstance(name, surname);

    while(1){
        New_Account = createAccountInstance(New_User->id);
        if(isIbanInDb(New_Account->IBan)){
            freeAccount(New_Account);
            continue;
        }
        break;
    }




    //Update files
    addUserToDb(New_User);
    addAccountToDb(New_Account);

    freeAccount(New_Account);
    freeUser(New_User);

}

void createUserAccount(char *user_id){
    struct Account *New_Account;

    New_Account = createAccountInstance(user_id);

    addAccountToDb(New_Account);

    freeAccount(New_Account);
    //Free Amount also?
}





bool isNameValid(const char *name){
    int i = 0;
    while(*(i+name)) {

        //Check if char is a letter
        if ((*(i+name)<'A')||(*(i+name)>'z')||(((*(i+name)>'Z') && (*(i+name)<'a')))){
            return 0;
        }
        i++;
    }
return 1;

}



int main() {


    char opcode[10], name[50], surname[50];

    short choice;

    printLoginInterface();


    scanf("%s %s %s", opcode, name, surname);

    if(!(isNameValid(name) && isNameValid(surname))){
        printf("Invalid credentials. Make sure you are using ASCII letters.\n");
        return 0;
    }


 //Make a function for these
    if (strcmp(opcode, "login") == 0) {
        printf("You are trying to login\n");

        if (isUserInDb(name, surname) == 1) {
           printMenuInterface(name,surname);
           scanf("%hd",&choice);
           optionsMenuInterface(choice);

        } else {
            printf("User not found");
            return 0;
        }

        return 0;
    }





    if (strcmp(opcode, "register") == 0) {
        printf("You are making a new user\n");
        createNewUser(name,surname);


    }
    else{
        printf("Invalid command, please try again.");

    }

}



