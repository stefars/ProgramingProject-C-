//
// Created by hidro on 3/16/2024.
//
#ifndef PROGRAMING_PROJECT_FILE_MANIP_H
#define PROGRAMING_PROJECT_FILE_MANIP_H

//MAKE SURE TO FIX FAIL CASE OPEN

void Add_Account_To_DB(struct Account* temp){

    FILE *file_pointer;

    file_pointer = fopen("E:\\Uni C_C++\\C\\CLion\\Programing Project\\Accounts.csv","a");
    if (file_pointer == NULL){
        perror("Couldn't open file");
        return;
    }

    fprintf(file_pointer,"%s,%s,%s,%lu\n",temp->IBan ,temp->id_user, temp->coin, temp->amount);

    fclose(file_pointer);

};

void Add_User_To_DB(struct User* temp){
    FILE *file_pointer;
    file_pointer = fopen("E:\\Uni C_C++\\C\\CLion\\Programing Project\\Users.csv","a");
    if (file_pointer == NULL){
        perror("Couldn't open file");
        return;
    }

    fprintf(file_pointer,"%s,%s,%s\n", temp->id, temp->name, temp->surname);

    fclose(file_pointer);


};

char  *Search_User_In_DB(char*name,char*surname){
    char *to_compare;
    char *token;
    char row[CHAR_MAX];

    to_compare = generate_user_id(name,surname);
    token = (char*)malloc(sizeof(char)*(strlen(to_compare)+1));
    if (token == NULL){
        perror("ERROR While opening the file to search for User.\n");
        free(to_compare);
        return NULL;

    }


    FILE *file_pointer;
    file_pointer = fopen("E:\\Uni C_C++\\C\\CLion\\Programing Project\\Users.csv","r");
    if (file_pointer == NULL){
        perror("ERROR While opening the file to search for User.\n");
        free(to_compare);
        return NULL;
    }

    while(feof(file_pointer) != true){

        fgets(row,CHAR_MAX,file_pointer);
        token = strtok(row,",");

        if (strcmp(token,to_compare) == 0){
            printf("User Found\n");
            fclose(file_pointer);
            free(to_compare);
            return strdup(token);
        }

    }

    printf("User NOT found");
    free(to_compare);
    free(token);
    printf("%p\n",token);
    return NULL;


}

char *Fetch_User_Accounts(char*user_id){



}

#endif //PROGRAMING_PROJECT_FILE_MANIP_H
