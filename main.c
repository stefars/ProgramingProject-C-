#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/structures_operations.h"
#include "Headers/file_manip.h"
#include "Headers/UI.h"
#include "Headers/generate.h"
#include "Headers/fetching.h"
#include "Headers/main_functions.h"
#include "Headers/user_input.h"



int main() {

    time_t t;
    srand((unsigned long long) (&t));

    char input_buffer[150];
    char option[50];
    char *opcode,*name,*surname;

    char is_running;
    char choice = '0';


    while(1) {
        strcpy(option,"Mirel Rodrigo");

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
                        awaitInput(input_buffer);
                        is_running = '0';

                        break;
                    }


                    while (1) {

                        if(strcmp(option,"return")==0)
                            break;
                        //clean screen;
                        printMenuInterface(Session->User->name, Session->User->surname);
                        getChoice(input_buffer, option);

                        if(strcmp(option,"ERROR") == 0){
                            awaitInput(input_buffer);
                            continue;
                        }

                        choice = *option;
                        switch (choice) {

                            case '1':

                                showAccounts(Session,input_buffer);
                                break;

                            case '2':

                                while (1) {
                                    if(strcmp(option,"back")==0)
                                        break;

                                    printAddAccountInterfaceAsk();

                                    getYesNo(input_buffer,option);



                                    switch (*option) {

                                        case 'Y': {
                                            addAccount(Session,input_buffer);
                                            break;
                                        }


                                        case 'N':

                                            strcpy(option,"back");
                                            break;

                                        default:
                                            printf("Invalid Command\n");
                                            awaitInput(input_buffer);
                                            break;
                                    }

                                }
                            break;
                            case '3':
                                //Edit Account select Account
                                    while (strcmp(option,"back")!= 0) {
                                        printAskOwnedIBAN();

                                        int index = getAccountByIBAN(input_buffer, option, Session);

                                        if (!strcmp(option, "ERROR") || !strcmp(option, "back"))
                                        {
                                            awaitInput(input_buffer);
                                            continue;
                                        }


                                        while (strcmp(option, "return") != 0) {


                                            printEditAccountMenu(Session->Accounts[index]);
                                            getChoice(input_buffer, option);



                                            switch (*option) {
                                                case '1':
                                                    editCurrency(input_buffer, option, Session->Accounts[index]);
                                                    break;

                                                case '2':
                                                    editIBAN(input_buffer, option, Session->Accounts[index]);
                                                    break;

                                                case '3':
                                                    deleteAccount(Session->Accounts[index]->IBan, &Session->Accounts[index], Session->User);
                                                    strcpy(option, "return");
                                                    break;

                                                case '4':
                                                    strcpy(option, "return");
                                                    break;

                                                default:
                                                    printf("Invalid choice\n");
                                                    awaitInput(input_buffer);
                                                    break;
                                            }
                                        }

                                        awaitInput(input_buffer);
                                    }


                                break;

                            case '4':

                                while (1) {

                                    addMoney(input_buffer, option, Session);

                                    if(strcmp(option,"ERROR") == 0)
                                        continue;

                                    if(strcmp(option,"back") == 0){
                                        break;
                                    }

                                    break;
                                }
                                break;

                            case '5':

                                transferMoney(input_buffer,option,Session);
                                if(strcmp(option,"ERROR") == 0) {
                                    awaitInput(input_buffer);
                                    continue;
                                }
                                if(strcmp(option,"back") == 0){
                                    break;
                                }

                                break;

                            case '6':

                                printf("Logging out\n");
                                is_running = '0';
                                strcpy(option,"return");
                                break;


                            default: {
                                printf("Invalid choice\n");
                                awaitInput(input_buffer);
                                break;
                            }

                        }


                    }

                    break;
                }
                case '2': {


                    if (isUserInDb(name, surname)) {
                        printf("User already in Data Base!\n");
                        is_running = '0';
                        awaitInput(input_buffer);
                        break;

                    }

                    createNewUser(name, surname);
                    printf("User created!\n");
                    awaitInput(input_buffer);
                    is_running = '0';
                    break;
                }

                case '0':
                    return 0;


                default:
                    break;

            }

        }


    }
}