#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"



void store( PRODUCT* product,int* nbProduits) {

    int m;
    printf("Combien de produits veux-tu entrer ? ");
    scanf("%d", &m);

    printf("Enter the information of the product\n");

    FILE* fichier = fopen("item.txt", "a");
    if (fichier == NULL) {
        printf("Erreur de l'ouverture du fichier");
        return;
    } else {
        for (int j = 0; j < m; j++) {
            printf("PRODUCT %d\n", j + 1);
            char tempName[50];
            printf("NAME: ");
            scanf("%s", tempName);

            // Vérifie si le produit existe déjà
            if (produitExiste(product, *nbProduits, tempName)) {
                printf("⚠️ Le produit '%s' existe déjà. Il ne sera pas ajouté.\n", tempName);
                j--; // Redemander l'entrée du produit
                continue;
            }

            // Sinon, on complète le reste des informations
            strcpy(product[*nbProduits].name, tempName);
            printf("QUANTITY: ");
            scanf("%d", &product[*nbProduits].quantity);
            printf("ID: ");
            scanf("%s", product[*nbProduits].id);
            printf("COST PRICE: ");
            scanf("%d", &product[*nbProduits].costPrice);
            printf("SELLING PRICE: ");
            scanf("%d", &product[*nbProduits].sellingPrice);

            // Ajout dans le fichier
            fprintf(fichier, "NOM:%s ,qty:%d,id:%s ,cost_price:%d ,selling_price:%d\n",
                    product[*nbProduits].name, product[*nbProduits].quantity,
                    product[*nbProduits].id, product[*nbProduits].costPrice,
                    product[*nbProduits].sellingPrice);

            (*nbProduits)++; // On met à jour le compteur de produits
        }
    }

    fclose(fichier);

}


int loadProductsFromFile(PRODUCT *product) {
    FILE* fichier = fopen("item.txt", "r");
    if (fichier == NULL) return 0;

    int i = 0;
    while (fscanf(fichier, "NOM:%s ,qty:%d,id:%s ,cost_price:%d ,selling_price:%d\n",
                  product[i].name,
                  &product[i].quantity,
                  product[i].id,
                  &product[i].costPrice,
                  &product[i].sellingPrice) == 5) {
        i++;
    }

    fclose(fichier);
    return i;
}

void print(int nb, PRODUCT* product) {

    if (nb == 0) {
        printf("No products stored.\n");
    }

    printf("\n==== LISTE DES PRODUITS ====\n");
    printf("%-15s %-10s %-10s %-15s %-15s\n", "Nom", "Quantité", "ID", "Prix Coût", "Prix Vente");
    for (int j = 0; j < nb; j++) {
        printf("%-15s %-10d %-10s %-15d %-15d\n",
            product[j].name,
            product[j].quantity,
            product[j].id,
            product[j].costPrice,
            product[j].sellingPrice);
    }
}

void lookup_student(int m, PRODUCT* product, char* matricule) {
    for (int j = 0; j < m; j++) {
        if (strcmp(matricule, product[j].id) == 0) {
            printf("NAME: %s\n", product[j].name);
            printf("QUANTITY: %d\n", product[j].quantity);
            printf("COST PRICE: %d\n", product[j].costPrice);
            printf("SELLING PRICE: %d\n", product[j].sellingPrice);
            printf("Product found successfully.\n");
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
void purchase(int m ,PRODUCT*product ,char*namepurchase){
    int purchaseQuantity = 0;
    int total = 0, totalProfit = 0;
    int choice = 0, b = 0;
    int found = 0;


    // Tableaux pour stocker les achats
    PRODUCT purchased[100];
    int quantities[100];
    int numPurchased = 0;


    l1:
    printf("name:");
    scanf("%s" ,namepurchase);

    for (int  j = 0; j < m; j++)
    {
        if (strcmp(namepurchase ,product[j].name)==0)
        {
            found=1;

            printf("QUANTITY:");
            scanf("%d", &purchaseQuantity);

            int lineTotal = purchaseQuantity * product[j].sellingPrice;
            int cost = purchaseQuantity * product[j].costPrice;
            int profit = lineTotal - cost;


            total += lineTotal;
            totalProfit += profit;



            purchased[numPurchased] = product[j];
            quantities[numPurchased] = purchaseQuantity;
            numPurchased++;

            printf("Total: %d\n", lineTotal);
            printf("Cost: %d\n", cost);
            printf("Profit: %d\n", profit);
            break;

        }

    }
    if (!found) {
        printf("\nProduct '%s' not found.\n", namepurchase);
    }
    printf("do you want to continue:\n1.yes\n 2.no");
         int n=0;
            scanf("%d",&n);
            if(n==1)
            {

                goto l1;


            }else if (n==2)
            {
                printf("do you want to generate the bill\n1.yes\n2.no\n");
                scanf("%d",& choice);
                if (choice==1)
                {
                    facture(numPurchased, product, quantities, total, totalProfit);

                }
                else if (choice==2)
                {
                    return;
                }

            }






}

void profit(){

}
void facture(int count,PRODUCT*product,int* quantities,int total,int profit){
    printf("\n===========================\n");
    printf("        FILLIN SUPERMARKET\n");
    printf("===========================\n\n");

    printf("%-15s %-10s %-15s %-15s\n", "Product", "Qty", "Unit Price", "Total Price");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        int lineTotal = quantities[i] * product[i].sellingPrice;
        printf("%-15s %-10d %-15d %-15d\n",
               product[i].name,
               quantities[i],
               product[i].sellingPrice,
               lineTotal);
    }

    printf("-------------------------------------------------------------\n");
    printf("%42s %10d\n", "TOTAL:", total);
    printf("%42s %10d\n", "PROFIT:", profit);
    printf("=============================================================\n");
    printf("Thank you for your purchase!\n");

    printf("Please visit us again!\n");
}
int produitExiste(PRODUCT*product,int nbProduits,char*namepurchase){
    for (int i = 0; i < nbProduits; i++)
    {
        if (strcmp(product[i].name,namepurchase)==0)
        {
            return 1; //trouve
        }
    }
    return 0; //pas trouve
}
