#include<stdio.h>
#include<string.h>
#include"function.h"

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