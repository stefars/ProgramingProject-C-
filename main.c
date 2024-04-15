#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/structures.h"
#include "Headers/file_manip.h"
#include <time.h>
#include "Headers/UI.h"
#include "Headers/generate.h"
#include "Headers/Fetching.h"
#include "Headers/Main Functions.h"



int main() {

    time_t t;
    srand((unsigned long long) (&t));

    char input_buffer[150];
    char *opcode,*name,*surname;


    char is_running = '1';
    char choice = '0';


    while(1) {

        //login interface
        printLoginInterface();

        choice = loginFunction(&opcode, &name, &surname, input_buffer);
        if (choice == '9')
            continue;

        is_running = '1';
        //Menu loop
        while (is_running == '1') {
            switch (choice) {
                case '1': {
                    struct Session *Session;

                    //Fetch User + Accounts data
                    Session = fetchUserData(name, surname);

                    if (Session == NULL) {
                        printf("User not registered.");


                    }

                    menu:

                    printMenuInterface(name, surname);


                    while (1) {
                        scanf(" %s", &choice);
                        if (strlen(&choice) > 1) {
                            printf("Command can only be 1 character long.\n");
                            continue;
                        }

                        switch (choice) {

                            case '1':

                                printf("Show Accounts (WIP)\n");
                                printShowAccountsInterface(Session);
                                break;

                            case '2':

                                while (1) {
                                    printf("Add Accounts (WIP)\n");


                                    printAddAccountInterfaceAsk();

                                    scanf(" %c", &choice);

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


                                }

                            case '3':

                                printf("Edit Account (WIP)\n");
                                // updateUserToDb(name,surname,);
                                break;

                            case '4':

                                printf("Add money (WIP)\n");

                                while (1) {


                                    addMoney(Session, choice);
                                    break;
                                }
                                break;

                            case '5':

                                printf("Transfer money (WIP)\n");

                                break;

                            case '6':

                                printf("Logging out\n");
                                free(Session);


                            default: {
                                printf("Invalid choice\n");
                                break;
                            }

                        }


                    }
                }
                case '2':
//REDUNDANT CHECKS
                    if (strcmp(opcode, "register") == 0) {
                        printf("You are making a new user\n");

                        if (isUserInDb(name, surname)) {
                            printf("User already in Data Base!\n");
                            is_running = '0';
                            break;


                        } else {
                            createNewUser(name, surname);
                            is_running = '0';
                            break;
                        }
                    }
                    break;


                case '0':
                    return 0;

                case '-':

                default:
                    printf("Invalid command, please try again.\n");
                    break;

            }

        }


    }
}