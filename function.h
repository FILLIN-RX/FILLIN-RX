#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct PRODUCT {
    char name[200];
    char id[20];
    int quantity;
    int costPrice;
    int sellingPrice;
} PRODUCT;

typedef struct user {
    char name[20];
    char password[20];
    PRODUCT* product;
    int product_count;
} user;

void store(int n, PRODUCT* product);
void print(int n, PRODUCT* product);
void lookup_student(int m, PRODUCT* product, char* matricule);
void free_Memory(int n, user* users);
void purchase(int m ,PRODUCT*product,char*namepurchase );
void facture(int count, PRODUCT *product, int *quantities, int total, int profit);


#endif
