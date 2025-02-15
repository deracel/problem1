#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib.h"

int main(){
    Matrix matr = {0, NULL};
    Border border = {0, 0, 0, 0};
    int eof = 0,  m = 0, n = 0, nulls = 0;
    input(&matr, &eof, &m, &n, &nulls);
    if (m == 0)
        printf("Your matrix size = 0\n\n");
    Matrix newmatr = {0, NULL};
    task(&newmatr, &matr, &m, &nulls, &border);
    if (eof != 1){
        printf ("-Old matrix\n");
        output(&matr);
        printf("\n");
        printf("-New matrix");
        if (nulls != 0) 
            printf("\t(%d zero lines were removed)\n", nulls);
        else
            printf("\n");
        output(&newmatr);
        printf("\n");
    }
    erase(&matr);
    erase(&newmatr);
    
   return 0;

}





