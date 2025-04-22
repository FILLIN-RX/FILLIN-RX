#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include"function.c"
#include <time.h>
#include <ctype.h>

int main() {

    int choice = 0, m = 0;
    char matricule[20];
    int nbProduits = 0;
    char namepurchase[200];
    PRODUCT product[200];
    nbProduits = loadProductsFromFile(product); // 🔁 recharge auto

    do {
        printf("1. Store product\n2. View product\n3. Look up product\n4. Purchase item\n5. View invoices\n6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            nbProduits = loadProductsFromFile(product); // 🔁 recharge auto
            store(product, &nbProduits);

                break;
            case 2:
                nbProduits = loadProductsFromFile(product); // 🔁 recharge auto
                print(nbProduits, product);
                break;
            case 3:
                nbProduits = loadProductsFromFile(product); // 🔁 recharge auto
                printf("Enter the ID of the product to find: ");
                scanf("%s", matricule);
                lookup_student(nbProduits, product, matricule);
                break;
            case 4:
                nbProduits = loadProductsFromFile(product); // 🔁 recharge auto
                purchase(nbProduits, product, namepurchase);
                break;
            case 5:
                afficherFactures();
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice < 6);



    return 0;
}
