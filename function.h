#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct PRODUCT {
    char name[200];
    char id[20];
    int quantity;
} PRODUCT;

typedef struct user {
    char name[20];
    char password[20];
    PRODUCT* product;
    int product_count;
} user;

void store(int n, PRODUCT* product);
void print(int n, PRODUCT* product);
void lookup_student(int m, PRODUCT* product, char* matricule);
void welcome(user* users, int n);
void Users(int n, user* users, char* old_user, char* old_password);
void menu(user* users);
void view_users(int n, user* users);
void free_Memory(int n, user* users);

#endif
