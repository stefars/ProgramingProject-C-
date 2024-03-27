#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Structure Operations/structures.h"
#include "DataBase Operations/file_manip.h"
#include <time.h>
#include "UI/UI.h"



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

            //FETCH DATA

            //CREATE USER STRUCT

            // STORE ACCOUNT STRUCTS IN LIST



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



