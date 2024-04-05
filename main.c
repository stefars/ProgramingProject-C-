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

    time_t t;
    srand((unsigned long long) (&t));

    char opcode[10], name[50], surname[50];



    char choice = '0';
    start:

    //login interface (function?)
while(1) {

    printLoginInterface();
    scanf("%s %s %s", opcode, name, surname);

    if (!(isNameValid(name) && isNameValid(surname))) {
        printf("Invalid characters. Make sure you are using ASCII letters.\n");
    }

    if (strcmp(opcode, "login") == 0) {
        choice = '1';
        break;
    }
    else if (strcmp(opcode, "register") == 0) {
        choice = '2';
        break;
    }
    else if (strcmp(opcode, "exit") == 0) {
        return 0;
    }
    else
        printf("Invalid command, please try again.");


}

while(1) {
    switch (choice) {
        case '1': {
            struct Session *Session;

            //Fetch User + Accounts data
            Session = fetchUserData(name, surname);

            if (Session == NULL) {
                printf("User not registered.");
                goto start;

            }

            menu:

            printMenuInterface(name, surname);


            while (1) {
                scanf(" %s", &choice);
                if(strlen(&choice)>1){
                    printf("Command can only be 1 character long.\n");
                    continue;
                }

                switch (choice) {

                    case '1':

                        printf("Show Accounts (WIP)\n");
                        printShowAccountsInterface(Session);
                        break;

                    case '2':

                        while(1){
                            printf("Add Accounts (WIP)\n");


                            printAddAccountInterfaceAsk();

                            scanf(" %c",&choice);

                            switch (choice) {

                                case 'Y': {
                                    struct Account *New_Account;

                                    New_Account = createAccountInstance(Session->User->id);

                                    Session->User->nr_accounts++;
                                    addAccountToDb(New_Account);
                                    addAccountToSession(New_Account, Session);

                                    printAddAccountInterface();

                                    //sleep?
                                    printAddAccountInterfaceSuccessful(New_Account);
                                    break;
                                }




                                case 'N':
                                    //UPDATE DATABASE
                                    goto menu;


                                default:
                                    printf("Invalid Command\n");
                                    break;
                            }




                            //MAKE SURE TO MODIFY FUNCTIONS FOR DETECTING ERROR






                        }

                    case '3':

                        printf("Edit Account (WIP)\n");
                       // updateUserToDb(name,surname,);
                        break;

                    case '4':

                        printf("Add money (WIP)\n");

                        break;

                    case '5':

                        printf("Transfer money (WIP)\n");

                        break;

                    case '6':

                        printf("Logging out\n");
                        free(Session);
                        goto start;

                    default: {
                        printf("Invalid choice\n");
                        break;
                    }

                }



            }
        }
            case '2':

                if (strcmp(opcode, "register") == 0) {
                    printf("You are making a new user\n");

                    if (isUserInDb(name, surname)) {
                        printf("User already in Data Base!\n");
                        goto start;
                    } else {
                        createNewUser(name, surname);
                        goto start;
                    }
                }
            break;


            default:
                printf("Invalid command, please try again.\n");
                break;

        }

}



}