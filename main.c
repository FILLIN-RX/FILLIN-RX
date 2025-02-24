#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"
#include"function.c"

int main(){
    int n=0,m=0;
    char matricule[20];
    PRODUCT*product;
    
    
    do
    {    
   
        printf("\n1.store product\n2.view product\n3.look product");
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
        
    
    default:
    printf("invalid option");
        break;
    }

    
} while (m<4);

    return 0;
}