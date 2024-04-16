#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/structures.h"
#include "Headers/file_manip.h"
#include "Headers/UI.h"
#include "Headers/generate.h"
#include "Headers/Fetching.h"
#include "Headers/Main Functions.h"



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
                        is_running = '0';
                        break;
                    }


                    while (1) {

                        if(strcmp(option,"return")==0)
                            break;
                        //clean screen;
                        printMenuInterface(Session->User->name, Session->User->surname);

                        getChoiceFunction(input_buffer,option);

                        if(strcmp(option,"ERROR") == 0){
                            continue;
                        }

                        choice = *option;
                        switch (choice) {

                            case '1':

                                printShowAccountsInterface(Session);
                                break;

                            case '2':

                                while (1) {
                                    if(strcmp(option,"back")==0)
                                        break;

                                    printAddAccountInterfaceAsk();

                                    // Need Changed;
                                    scanf(" %c", &choice);

                                    switch (choice) {

                                        case 'Y': {
                                            struct Account *New_Account;

                                            New_Account = createAccountInstance(Session->User->id);

                                            Session->User->nr_accounts++;
                                            addAccountToDb(New_Account);
                                            addAccountToSession(New_Account, Session);

                                            modifyUserTempFile(Session->User);
                                            updateUsersFileOriginal();

                                            printAddAccountInterface();

                                            //sleep?
                                            printAddAccountInterfaceSuccessful(New_Account);
                                            break;
                                        }


                                        case 'N':
                                            //UPDATE DATABASE
                                            strcpy(option,"back");
                                            break;

                                        default:
                                            printf("Invalid Command\n");
                                            break;
                                    }


                                }

                            case '3':
                                //Edit Account select Account
                                while(1){
                                    if(!strcmp(option,"back"))
                                        break;
                                    printf("Enter Account:\n");
                                    int index = getAccountByIBAN(input_buffer,option,Session);

                                    if(strcmp(option,"ERROR") == 0)
                                        continue;
                                    if(!strcmp(option,"back"))
                                       break;

                                    //Edit Account Menu
                                    while(1) {
                                        if(!strcmp(option,"return"))
                                            break;

                                        printf("[1] Edit Currency\n[2] Edit IBAN\n[3] Delete\n[4] Return\n");
                                        getChoiceFunction(input_buffer, option);

                                        if (strcmp(option, "ERROR") == 0) {
                                            continue;
                                        }

                                        choice = *option;

                                        switch (choice){

                                            case '1':
                                                //Currency Edit;
                                                editCurrency(input_buffer,option,Session->Accounts[index]);
                                                if (strcmp(option, "ERROR") == 0) {
                                                    continue;
                                                }
                                                if (strcmp(option, "back") == 0) {
                                                    continue;
                                                }

                                                break;
                                            case '2':
                                                //Edit IBAN
                                                editIBAN(input_buffer,option,Session->Accounts[index]);
                                                if (strcmp(option, "ERROR") == 0) {
                                                    continue;
                                                }
                                                if (strcmp(option, "back") == 0) {
                                                    continue;
                                                }

                                                break;
                                            case '3':
                                                //Delete Account.
                                                deleteAccount(Session->Accounts[index]->IBan,&Session->Accounts[index],Session->User);
                                                if (strcmp(option, "ERROR") == 0) {
                                                    continue;
                                                }
                                                if (strcmp(option, "back") == 0) {
                                                    continue;
                                                }


                                                break;
                                            case '4':
                                                strcpy(option,"return");
                                                continue;

                                            default:
                                                printf("No clue");
                                                break;
                                        }


                                        break;
                                    }



                                    break;
                                }

                                break;

                            case '4':

                                while (1) {

                                    addMoneyFunction(input_buffer,option,Session);

                                    if(strcmp(option,"ERROR") == 0)
                                        continue;

                                    if(strcmp(option,"back") == 0){
                                        break;
                                    }

                                    break;
                                }
                                break;

                            case '5':

                                printf("Transfer money (WIP)\n");

                                break;

                            case '6':

                                printf("Logging out\n");
                                is_running = '0';
                                strcpy(option,"return");
                                break;


                            default: {
                                printf("Invalid choice\n");
                                break;
                            }

                        }


                    }

                    break;
                }
                case '2': {
                    //COULD BE A FUNCTION
                    printf("You are making a new user\n");

                    if (isUserInDb(name, surname)) {
                        printf("User already in Data Base!\n");
                        is_running = '0';
                        break;

                    }

                    createNewUser(name, surname);
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