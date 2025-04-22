#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include <time.h>
#include <ctype.h>



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
            char tempId[20];
            printf("NAME: ");
            scanf("%s", tempName);
            printf("ID: ");
            scanf("%s", tempId);

            // Vérifie si le produit existe déjà
            if (produitExiste(product, *nbProduits, tempName,tempId)) {
                printf("⚠️ Le produit '%s' existe déjà. Il ne sera pas ajouté.\n", tempName);
                j--; // Redemander l'entrée du produit
                continue;
            }

            // Sinon, on complète le reste des informations
            strcpy(product[*nbProduits].name, tempName);
            strcpy(product[*nbProduits].id, tempId);
            printf("QUANTITY: ");
            scanf("%d", &product[*nbProduits].quantity);
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

     l2:       printf("QUANTITY:");
            scanf("%d", &purchaseQuantity);


        if (retirerDuStock(product, m, namepurchase, purchaseQuantity)) {
            // tu peux continuer avec la facture
        } else {
            // erreur de stock ou produit introuvable
            goto l2;
        }

            int lineTotal = purchaseQuantity * product[j].sellingPrice;
            int cost = purchaseQuantity * product[j].costPrice;
            int profit = lineTotal - cost;


            total += lineTotal;
            totalProfit += profit;



            purchased[numPurchased] = product[j];
            quantities[numPurchased] = purchaseQuantity;
            numPurchased++;

            printf("Total: %d\n", total);
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
                    facture(numPurchased, purchased, quantities, total, totalProfit);

                }
                else if (choice==2)
                {
                    return;
                }

            }






}
void updateProductsToFile(PRODUCT *products, int count) {
    FILE *f = fopen("produits.txt", "w");
    if (!f) {
        printf("Erreur d'ouverture du fichier produits.txt\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(f, "%s %d %d %d %d\n",
            products[i].name,
            products[i].quantity,
            products[i].id,
            products[i].costPrice,
            products[i].sellingPrice
        );
    }

    fclose(f);
}


void facture(int count,PRODUCT*product,int* quantities,int total,int profit){
    printf("\n===========================\n");
    printf("        FILLIN SUPERMARKET\n");
    printf("===========================\n\n");


    // 1. Générer et afficher la facture
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf( "\n================= FACTURE =================================\n");

    printf( "Date: %02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
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

    // 2. Enregistrer la facture dans un fichier
    FILE* f = fopen("factures.txt", "a"); // ← fichier historique
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier facture.\n");
        return;
    }

    fprintf(f, "\n================= FACTURE =================\n");

    fprintf(f, "Date: %02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(f, "%-15s %-10s %-15s %-15s\n", "Product", "Qty", "Unit Price", "Total Price");
    fprintf(f, "-------------------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        int lineTotal = quantities[i] * product[i].sellingPrice;
        fprintf(f,"%-15s %-10d %-15d %-15d\n",
               product[i].name,
               quantities[i],
               product[i].sellingPrice,
               lineTotal);
    }

    fprintf(f, "-------------------------------------------------------------\n");
    fprintf(f, "%42s %10d\n", "TOTAL:", total);
    fprintf(f, "%42s %10d\n", "PROFIT:", profit);
    fprintf(f, "=============================================================\n");
    printf("Thank you for your purchase!\n");

    printf("Please visit us again!\n");
    fclose(f);
}

void afficherFactures() {
    FILE* fichier = fopen("factures.txt", "r");
    if (fichier == NULL) {
        printf("⚠️ Impossible d'ouvrir l'historique des factures.\n");
        return;
    }

    printf("\n===== HISTORIQUE DES FACTURES =====\n\n");

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }

    fclose(fichier);
}


// Fonction de comparaison insensible à la casse pour les chaînes
int strcasecmp_custom(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2)) {
            return 0; // Les chaînes ne sont pas égales
        }
        s1++;
        s2++;
    }
    return *s1 == *s2; // Retourne vrai si les deux chaînes sont égales (fin ou caractères identiques)
}
// Fonction pour vérifier si un produit existe déjà
int produitExiste(PRODUCT*product,int nbProduits,char*namepurchase,char*id){
    for (int i = 0; i < nbProduits; i++)
    {
        if (strcasecmp_custom(product[i].name, namepurchase) == 1 || strcasecmp_custom(product[i].id, id) == 1)
        {
            return 1; //trouve
        }
    }
    return 0; //pas trouve
}

int retirerDuStock(PRODUCT* product, int nbProduits, char nomProduit[], int quantiteDemandee) {
    for (int i = 0; i < nbProduits; i++) {
        if (strcasecmp(product[i].name, nomProduit) == 0) {
            if (product[i].quantity >= quantiteDemandee) {
                product[i].quantity -= quantiteDemandee;
                printf("🟢 %d unité(s) de %s retirée(s) du stock. Nouveau stock : %d\n",
                       quantiteDemandee, product[i].name, product[i].quantity);
                return 1; // succès
            } else {
                printf("🔴 Stock insuffisant pour %s. (Dispo : %d, demandé : %d)\n",
                       product[i].name, product[i].quantity, quantiteDemandee);
                return 0; // échec
            }
        }
    }

    printf("🔴 Produit %s introuvable dans le stock.\n", nomProduit);
    return -1; // produit introuvable
}
