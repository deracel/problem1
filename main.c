#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib.h"

int main(){
    Matrix matr = {0, NULL};
    Border border = {0, 0, 0, 0};
    int eof = 0,  m = 0, n = 0, nulls = 0;
    input(&matr, &eof, &m, &n, &nulls);
    
    Matrix newmatr = {0, NULL};
    task(&newmatr, &matr, &m, &nulls, &border);
    if (eof != 1){
        printf ("-Old matrix\n");
        output(&matr);
        printf("\n");
        printf("-New matrix\n");
        output(&newmatr);
        printf("\n");
    }
    erase(&matr);
    erase(&newmatr);
    
    /*if (input(&matr) == 0){
        printf("%s\n, End of file occured");
        return 0;
    }*/
   return 0;

}





