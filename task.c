#include <stdlib.h>
#include <stdio.h>
#include "lib.h"


void minmax(int* begin, int* end, Border* border){
    if (border->indexneg < border->indexpos)
        {*begin = border->indexneg; *end = border->indexpos;}
    else
        {*begin = border->indexpos; *end = border->indexneg;}
}



void createline(Matrix* matr, Matrix* newmatr, int line, Border* border, int n){
    int begin = 0; int end = 0;
    minmax(&begin, &end, border);
    newmatr->stroki[line].n = (end - begin) + 1;
    if(((end - begin) + 1) > 0){
        newmatr->stroki[line].arr = malloc(newmatr->stroki[line].n * sizeof(int));
        int k = begin;
        if (newmatr->stroki[line].arr == NULL)
		    {printf("Memory allocation faled\n"); exit(1);}

        for (int i = 0; i < newmatr->stroki[line].n; i++){
            newmatr->stroki[line].arr[i] = matr->stroki[n].arr[k];
            k++;
        }
    }
    /*if(((end - begin) + 1) == 0)
        newmatr->stroki[line].arr = malloc(1 * sizeof(int));*/
}




void task(Matrix* newmatr, Matrix* matr, int* m, int* nulls, Border* border){
    /*(*nulls) = 0;*/
    newmatr->lines = *m - *nulls;
    int line = 0;
    newmatr->stroki = malloc ((*m - *nulls) * sizeof(Line));
    for (int i = 0; i < *m; i++){
        border->pos = 0; border->neg = 0; border->indexneg = 0; border->indexpos = 0;
        for (int j = 0; j < matr->stroki[i].n; j++){
            if (matr->stroki[i].arr[j] < 0 && border->neg == 0){
                border->neg = matr->stroki[i].arr[j];
                border->indexneg = j;
            }
            if (matr->stroki[i].arr[j] > 0 && border->pos == 0){
                border->pos = matr->stroki[i].arr[j];
                border->indexpos  = j;
            }
            if (border->pos != 0 && border->neg != 0){
                createline(matr, newmatr, line, border, i);
                line++;
                break;
            }
            if (((border->pos != 0 && border->neg == 0) || (border->pos == 0 && border->neg != 0)) && (j == matr->stroki[i].n - 1)){
                border->indexpos = 0;
                border->indexneg = j;
                createline(matr, newmatr, line, border, i);
                line++;
            }
            /*if (border->pos == 0 && border->neg == 0 && (j == matr->stroki[i].n - 1)){
                border->indexpos = -1;
                border->indexneg = 0;
                createline(matr, newmatr, line, border, i);
            }*/
            /*line++;*/
        }
    }
}