#ifndef  FUNCTION_H
#define FUNCTION_H

typedef struct PRODUCT PRODUCT ;

struct PRODUCT{
    
    char name[200];
    char id[20];
    int quantity;

};
void store(int n, PRODUCT*product);

void print(int n ,PRODUCT*product);

int lookup_student(int n ,PRODUCT*product,char *matricule);





#endif