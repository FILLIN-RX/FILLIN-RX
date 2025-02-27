#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include"function.c"

int main() {
    int n = 0, p = 0;
    char old_user[20], old_password[20];
    user* users = NULL;

    do {
        printf("1. Register as new user\n2. Login\n3. View users\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &p);

        switch (p) {
            case 1:
                printf("Enter the number of users: ");
                scanf("%d", &n);
                users = (user*)malloc(n * sizeof(user));
                if (users == NULL) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }
                welcome(users, n);
                free_Memory(n, users);
                free(users);
                users = NULL;
                break;

            case 2:
                if (n <= 0) {
                    printf("No users registered yet.\n");
                    break;
                }
                printf("Login information:\n");
                printf("NAME: ");
                scanf("%s", old_user);
                Users(n, users, old_user, old_password);
                break;

            case 3:
                view_users(n, users);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    } while (p != 4);

    return 0;
}
