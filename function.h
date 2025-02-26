#ifndef  FUNCTION_H
#define FUNCTION_H

typedef struct PRODUCT PRODUCT ;

struct PRODUCT{

    char name[200];
    char id[20];
    int quantity;

};
typedef struct user user;
struct user
{
    char name[20];
    char password[20];
    PRODUCT*product;
    int product_count;
};

void store(int n, PRODUCT*product);

void print(int n ,PRODUCT*product);

void lookup_student(int m ,PRODUCT*product,char *matricule);

void welcome(user*user, int n);

void users(int n,user*user,char*old_user[20],char*old_password[20]);

void menu(user*users);

void view_users(int n,user*users);

void free_Memory(int n,user*users);



#endif
