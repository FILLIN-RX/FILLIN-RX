#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

void welcome(user* users, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter your name:\n");
        scanf("%s", users[i].name);
        printf("Enter your password:\n");
        scanf("%s", users[i].password);
        users[i].product = NULL;
        users[i].product_count = 0;
        printf("Registered successfully\n");
        menu(&users[i]);
    }
}

void Users(int n, user* users, char* old_user, char* old_password) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(old_user, users[i].name) == 0) {
            found = 1;
            while (1) {
                printf("PASSWORD:\n");
                scanf("%s", old_password);
                if (strcmp(old_password, users[i].password) == 0) {
                    menu(&users[i]);
                    return;
                } else {
                    printf("Invalid password. Try again.\n");
                }
            }
        }
    }
    if (!found) {
        printf("No user found.\n");
    }
}

void view_users(int n, user* users) {
    if (users == NULL || n <= 0) {
        printf("No users registered.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("USER %d\n", i + 1);
        printf("NAME: %s\n", users[i].name);
        printf("PASSWORD: (hidden for security)\n");
    }
}

void store(int m, PRODUCT* product) {
    printf("Enter the information of the product\n");
    for (int j = 0; j < m; j++) {
        printf("PRODUCT %d\n", j + 1);
        printf("NAME: ");
        scanf("%s", product[j].name);
        printf("QUANTITY: ");
        scanf("%d", &product[j].quantity);
        printf("ID: ");
        scanf("%s", product[j].id);
    }
}

void print(int m, PRODUCT* product) {
    for (int j = 0; j < m; j++) {
        printf("PRODUCT %d\n", j + 1);
        printf("NAME: %s\n", product[j].name);
        printf("QUANTITY: %d\n", product[j].quantity);
        printf("ID: %s\n", product[j].id);
    }
}

void lookup_student(int m, PRODUCT* product, char* matricule) {
    for (int j = 0; j < m; j++) {
        if (strcmp(matricule, product[j].id) == 0) {
            printf("NAME: %s\n", product[j].name);
            printf("QUANTITY: %d\n", product[j].quantity);
            return;
        }
    }
    printf("\nProduct with ID %s not found.\n", matricule);
}

void free_Memory(int n, user* users) {
    for (int i = 0; i < n; i++) {
        if (users[i].product != NULL) {
            free(users[i].product);
            users[i].product = NULL;
        }
    }
}

void menu(user* u) {
    int choice = 0, m = 0;
    char matricule[20];

    do {
        printf("\n1. Store product\n2. View product\n3. Look up product\n4. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of items to register: ");
                scanf("%d", &m);
                u->product = (PRODUCT*)malloc(m * sizeof(PRODUCT));
                if (u->product == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                u->product_count = m;
                store(m, u->product);
                break;
            case 2:
                if (u->product == NULL) {
                    printf("No products stored.\n");
                } else {
                    print(u->product_count, u->product);
                }
                break;
            case 3:
                printf("Enter the ID of the product to find: ");
                scanf("%s", matricule);
                lookup_student(u->product_count, u->product, matricule);
                break;
            case 4:
                free(u->product);
                u->product = NULL;
                return;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice < 4);
}
