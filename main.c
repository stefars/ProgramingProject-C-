#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "file_manip.h"
#include <time.h>
#include <conio.h>

//FIX THIS


void Init_New_User(){
    char x[100],y[100];
    scanf("%s",x);
    scanf("%s",y);

    struct User New_User;
    struct Account New_Account;

    //Generate new instances
    New_User = Create_User_Instance(x, y);
    New_Account = Create_Account_Instance(New_User.id);

    //Update files
    Add_User_To_DB(&New_User);
    Add_Account_To_DB(&New_Account);

}

void Create_Account_For_User(char *){



}

int main() {

    while (1) {
        char x;




        scanf("%c", &x);

        if (x == *"Y") {
            system("cls");
            printf("yes");

        }
    }
    return 0;


}
