#include<stdio.h>
#include<string.h>
#include"function.h"
int i=0;
void welcome(user*users ,int n){
    for ( i = 0; i < n; i++)
    {



    printf("Enter your name:\n");
    scanf("%s", users[i].name);
    printf("enter your password:\n");
    scanf("%s",users[i].password);
    users[i].product = NULL;
    users[i].product_count=0;
    printf("Registered successfully\n");
     menu(&users[i]);

    }

}
void Users(int n,user*users,char*old_user,char*old_password){
    int i=0;
    for ( i = 0; i < n; i++)
    {
        if (strcmp(old_user,users[i].name)==0)
        {
         l1:printf("PASSWORD:\n");
            scanf("%s",old_password);
            if (strcmp(old_password,users[i].password)==0)
            {
                menu(&users[i]);
            }else
            {
                printf("invalid password\n");
                goto l1;
            }



        }else
        {
            printf("no user found\n");
        }



    }



}
void view_users(int n,user*users){
    for ( i = 0; i < n; i++)
    {
        printf("USER %d\n",i+1);
        printf("NAME:%s\n",users[i].name);
        printf("PASSWORD:\n-------------\n");
    }

}

void store(int m, PRODUCT*product){
    int j=0;
    printf("Enter the information of the product\n");
    for ( j = 0; i < m; j++)
    {

        printf("PRODUCT:%d\n",i+1);
        printf("NAME\n");
        scanf("%s",product[j].name);
        printf("quantity\n");
        scanf("%d" ,&product[j].quantity);
        printf("id:\n");
        scanf("%s" ,product[j].id);

    }
}

void print(int m ,PRODUCT*product){
    int j=0;
    for ( j = 0; j < m; j++)
    {
        printf("product: %d\n",i+1);
        printf("NAME:%s\n",product[j].name);
        printf("QUANTITY:%d\n",product[j].quantity);
        printf("ID:%s\n",product[j].id);
    }



}
void lookup_student(int m ,PRODUCT*product,char *matricule){
    int j,b;

    for ( j = 0; j< m; j++)
    {
        b=strcmp(matricule,product[j].id);
        if (b==0)
        {
            printf("NAME:%s\n",product[j].name);
            printf("quantity:%d\n",product[j].quantity);

            return ;
        }
    }


    printf("\n Product with id %s not found.\n" , matricule);


}

void free_Memory(int n,user*users){
    for ( i = 0; i < n; i++)
    {
        free(users[i].product);
    }

}
void menu(user*users){
    int choice=0,m=0;
    char matricule[20],old_user[20],old_password[20];
    PRODUCT*product;
    user*user;


do
{

    printf("\n1.store product\n2.view product\n3.look product\n4.back");
    printf("\nenter you operation\n");
    scanf("%d",&choice);
switch (choice)
{
case 1:
        printf("Enter the number of items to register\n");
        scanf("%d",&m);
        product=(PRODUCT*)malloc(m*sizeof(PRODUCT));
        if (product==NULL)
        {
            printf("Erreur d'allocation de memoire");
            return ;
        }
        users->product_count=m;


        store(m,users->product);

    break;
case 2:
        print(m ,users->product);
    break;
case 3:
        printf("enter the id of the product to find\n");
        scanf("%s",matricule);
        lookup_student(users->product_count,product,matricule);
    break;
case 4:
        free(product);
        return;

        break;


default:
printf("invalid option");
    break;
}


} while (choice<4);


}
