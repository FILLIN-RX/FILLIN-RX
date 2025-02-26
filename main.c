#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"
#include"function.c"

int main(){
    int n=0,p=0;
    char old_user[20],old_password[20];
    PRODUCT*product;
    user*users;


    do
    {
        printf("1.Register as new user\n2.login\n3.view users\n");
        scanf("%d",&p);
        switch (p)
        {
        case 1:
            printf("enter the number of users\n");
            scanf("%d",&n);
            user*users=(user*)malloc(n*sizeof(user));

            welcome(users,n);
            free_Memory(n,users);

            free(users);


            break;
        case 2:
            users=(user*)malloc(n*sizeof(user));
            if (users==NULL)
            {
                printf("memory allocation failled");
                return 1;
            }
            printf("login information\n");
            printf("NAME:\n");
            scanf("%s", old_user);
            Users(n,users,old_user,old_password);
            free(users);
            break;
        case 3:
            users=(user*)malloc(n*sizeof(user));
            if (users==NULL)
            {
                printf("memory allocation failled");
                return 1;
            }
            view_users(n,users);
            free(users);
            break;

        default:
            printf("invalid option");
            break;
        }
    } while (p<4);

    return 0;

}
