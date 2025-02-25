#include<stdio.h>
#include<string.h>
#include"function.h"
int i=0;
void welcome(user*users){
    printf("Enter your name:\n");
    scanf("%s", users->name);
    printf("enter your password:\n");
    scanf("%s",users->password);
    printf("Registered successfully\n");
     menu();

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
                menu();
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

void store(int n, PRODUCT*product){
    int i=0;
    printf("Enter the information of the product\n");
    for ( i = 0; i < n; i++)
    {
       
        printf("PRODUCT:%d\n",i+1);
        printf("NAME\n");
        scanf("%s",product[i].name);
        printf("quantity\n");
        scanf("%d" ,&product[i].quantity);
        printf("id:\n");
        scanf("%s" ,product[i].id);

    }
}

void print(int n ,PRODUCT*product){
    int i=0;
    for ( i = 0; i < n; i++)
    {
        printf("product: %d\n",i+1);
        printf("NAME:%s\n",product[i].name);
        printf("QUANTITY:%d\n",product[i].quantity);
        printf("ID:%s\n",product[i].id);
    }
    
    

}
int lookup_student(int n ,PRODUCT*product,char *matricule){
    int i,b;
   
    for ( i = 0; i < n; i++)
    {
        b=strcmp(matricule,product[i].id);  
        if (b==0)
        {
            printf("NAME:%s\n",product[i].name);
            printf("quantity:%d\n",product[i].quantity);
        } 
    }
   
    
        return -1;
    

}
int menu(){
    int n=0,m=0;
    char matricule[20],old_user[20],old_password[20];
    PRODUCT*product;
    user*user;


do
{    

    printf("\n1.store product\n2.view product\n3.look product\n4.back");
    printf("\nenter you operation\n");
    scanf("%d",&m);
switch (m)
{
case 1:
        printf("Enter the number of items to register\n");
        scanf("%d",&n);
        product=(PRODUCT*)malloc(n*sizeof(PRODUCT));
        if (product==NULL)
        {
            printf("Erreur d'allocation de memoire");
            return 1;
        }
        
        
        store(n,product);
        free(product);
    break;
case 2:
        print(n ,product);
    break;
case 3:
        printf("enter the id of the product to find\n");
        scanf("%s",matricule);
        lookup_student(n,product,matricule);
    break;
case 4:
        return -1;

        break;
    

default:
printf("invalid option");
    break;
}


} while (m<4);

return 0;
}
