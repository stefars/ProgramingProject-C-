#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Structure Operations/structures.h"
#include "DataBase Operations/file_manip.h"
#include <time.h>
#include "UI/UI.h"
#include "Structure Operations/Generative Algorithms/generate.h"
#include "DataBase Operations/Data Fetch/Fetching.h"


int main() {


    char opcode[10], name[50], surname[50];

    char choice = '0';

    printLoginInterface();

//while here?
    scanf("%s %s %s", opcode, name, surname);

    if (!(isNameValid(name) && isNameValid(surname))) {
        printf("Invalid characters. Make sure you are using ASCII letters.\n");
        return 0;
    }

    if (strcmp(opcode, "login") == 0)
        choice = '1';
    else if (strcmp(opcode, "register") == 0)
        choice = '2';
    else
        printf("Invalid command, please try again.");


    //end while here?

//while here?
    switch (choice) {
        case '1':
            if (1) {
                struct Session *Session;

                //Fetch User + Accounts data
                Session = fetchUserData(name,surname);


                printMenuInterface(name, surname);
                scanf(" %c",&choice);


                //While here?

                switch (choice){

                    case '1':

                        printf("Show Accounts (WIP)\n");
                        printShowAccountsInterface(Session);
                        break;

                    case '2':

                        printf("Add Accounts (WIP)\n");


                        printAddAccountInterface();

                        //USE ID AFTER FETCHING

                        createUserAccount(generateUserId(name,surname));

                        Session->User->nr_accounts ++;

                        //UPDATE SESSION


                        //MAKE SURE TO MODIFY FUNCTIONS FOR DETECTING ERROR

                        printAddAccountInterfaceSuccessful();



                        break;

                    case '3':

                        printf("Edit Account (WIP)\n");

                        break;

                    case '4':

                        printf("Add money (WIP)\n");

                        break;

                    case '5':

                        printf("Transfer money (WIP)\n");

                        break;

                    case '6':

                        printf("Logging out");

                        break;

                    default:

                        printf("Invalid choice");
                        break;

                }




            } else {
                printf("User not found");
                return 0;
            }
            break;


        case '2':

            if (strcmp(opcode, "register") == 0) {
                printf("You are making a new user\n");

                if (isUserInDb(name,surname)) {
                    printf("User already in Data Base!");
                    break;
                }

                else {
                    createNewUser(name, surname);
                    break;
                }
            }
            break;
        default:
            printf("Invalid command, please try again.");
            break;

    }





    //Make a function for these



}