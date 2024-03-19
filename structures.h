//
// Created by hidro on 3/16/2024.
//

#ifndef PROGRAMING_PROJECT_STRUCTURES_H
#define PROGRAMING_PROJECT_STRUCTURES_H
#include <stdlib.h>
#include <time.h>

//Find new place for these?
char *generate_user_id(char* name,char* surname){

    char *to_generate,*seed;

    to_generate = (char*)malloc(sizeof(char)*(strlen(name)+strlen(surname))+1);
    if (to_generate == NULL){
        printf("Couldn't find space in memory\n");
        return NULL;  //Error code
    }

    //concat name & username

    strcpy(to_generate,name);
    strcat(to_generate,surname);


    int x = (int) strlen(to_generate);

    seed = (char*)malloc(sizeof(char)*(x+1));
    if (seed == NULL){
        printf("Couldn't find space in memory\n");
        free(to_generate);
        return NULL;  //Error code

    }


    for(int i = 0;i < x;i++){

        *(seed+i) =(char)(*(to_generate+i)+4);
    }

    *(seed+x) = '\0';


    free(to_generate);
    return seed;




}

char *generate_IBan(){

    int sum = 0;
    char IBan_rule_number;
    char *IBan_control_numbers;
    char *IBan_random_letters;
    char *IBan;

    IBan_random_letters = (char*)malloc(sizeof(char) * 6);
    if (IBan_random_letters == NULL){
        printf("Couldn't find space in memory\n");
        return NULL;  //Error code
    }

    IBan_control_numbers = (char*)malloc(sizeof(char) * 6);
    if (IBan_control_numbers == NULL){
        printf("Couldn't find space in memory\n");
        return NULL;  //Error code
    }


    time_t t;
    srand((unsigned long long) (&t));


    for (int i = 0; i < 5; i++){
        int temp = rand() % 10;
        sum += temp;
        sprintf(IBan_control_numbers + i, "%d", temp);

    }

    for (int i = 0; i < 5; i++){
        int temp = rand() % (25) + 65;  // A - Z
        sprintf(IBan_random_letters + i, "%c", temp);

    }

    *(IBan_random_letters + 6) = '\0';
    *(IBan_control_numbers + 6) = '\0';


    if(sum <= 25){
        IBan_rule_number = 1;
    }
    else{
        IBan_rule_number = 0;
    }

    sprintf(&IBan_rule_number,"%d",IBan_rule_number);

    IBan = (char*)malloc(sizeof(char)*16);
    strcpy(IBan,&IBan_rule_number);
    strcpy(IBan+1,"BANK");
    strcpy(IBan+5,IBan_random_letters);
    strcpy(IBan+10,IBan_control_numbers);

    *(IBan+16) = '\0';


    free(IBan_control_numbers);
    free(IBan_random_letters);

    return IBan;

}



struct User {
    char* id;
    char* name;
    char* surname;
    int nr_accounts;
};

struct Account {
    char* IBan;
    char* id_user;
    char* coin;
    unsigned long amount;

};

struct Account Create_Account_Instance(char* id){

    struct Account temp;

    temp.IBan = generate_IBan();
    temp.id_user = (char*)malloc(sizeof(char)*strlen(id));
    temp.coin = (char*)malloc(sizeof(char));

    strcpy(temp.id_user,id);
    strcpy(temp.coin,"R");
    temp.amount = 0;

    return temp;
};

struct User Create_User_Instance(char* name, char* surname){

    struct User temp;

    temp.id = generate_user_id(name,surname);
    temp.name = (char*)malloc(sizeof(char)*strlen(name)+1);
    temp.surname = (char*)malloc(sizeof(char)*strlen(surname)+1);

    strcpy(temp.name,name);
    strcpy(temp.surname,surname);
    temp.nr_accounts = 1;


    return temp;
};


#endif //PROGRAMING_PROJECT_STRUCTURES_H
