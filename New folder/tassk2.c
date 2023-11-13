#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERS 10

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char flag[] ;
};

int registerUser(struct User* users, int* numUsers, char* username, char* password ,char* flag) {
    if (*numUsers >= MAX_USERS) {
        return 0; // Maximum number of users reached
    }

    for (int i = 0; i < *numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return -1; // Username already exists
        }
    }

    strcpy(users[*numUsers].username, username);
    strcpy(users[*numUsers].password, password);
     strcpy(users[*numUsers].flag, flag);
    (*numUsers)++;

    return 1; // Registration successful
}

int loginUser(struct User* users, int numUsers, char* username, char* password  , char* flag ) {
       char True1[]="true";
       char True2[]="1";
       char False1[]="false";
       char False2[]="0";
    for (int i = 0; i < numUsers; i++) {
        
        // هنضيف لو الفلاج ب1 يدخل  لو لا ميدخلش
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if((strcmp(users[i].flag,True1))==0||(strcmp(users[i].flag,True2))==0){
            return 1; // Login successful
            }
             else{
                 return 0; // Login failed
             }
        }
    }
    return 0; // Login failed
}

int main() {
    struct User users[MAX_USERS];
    int numUsers = 0;

    int choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char flag[6];
    while (1) {
        printf("1. Register\n");
        printf("2. Login\n");
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Username: ");
                scanf("%s", username);
                printf("Password: ");
                scanf("%s", password);
                printf("active: ");
                scanf("%s", flag);
                

                int result = registerUser(users, &numUsers, username, password,flag);
                if (result == 1) {
                    printf("Registration successful!\n");
                } else if (result == 0) {
                    printf("Maximum number of users reached!\n");
                } else if (result == -1) {
                    printf("Username already exists!\n");
                }
                break;

            case 2:
                printf("Username: ");
                scanf("%s", username);
                printf("Password: ");
                scanf("%s", password);
            
                if (loginUser(users, numUsers, username, password ,flag)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed!\n");
                }
             

            

            
        }
    }

    return 0;
}