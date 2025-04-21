#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include"function.c"

int main() {

    int choice = 0, m = 0;
    char matricule[20];
    char namepurchase[200];
    PRODUCT product[200];

    do {
        printf("\n1. Store product\n2. View product\n3. Look up product\n4. purchase item\n5.back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                store(product);
                break;
            case 2:
                if (product == NULL) {
                    printf("No products stored.\n");
                } else {
                    print( m,  product);
                }
                break;
            case 3:
                printf("Enter the ID of the product to find: ");
                scanf("%s", matricule);
                lookup_student(m,product, matricule);
                break;
            case 4:

                purchase(m,product,namepurchase);
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice < 5);



    return 0;
}
