#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int getint(int *intx, int trigger){
	int c = 0;
	int a = 0;
	int kol = 1;
	int tryagain = 0;
	while(c != 1  ||  kol != 0){ 
		kol = 0;
		if (tryagain == 1)
			printf("Try again: ");
		c = scanf("%d", intx);
		printf("--");
		if (c == EOF && a != EOF){//EOF
            printf("\n\t\t\t\tEnd of File\n"); kol = -2; return 1;
            }
		
		if ((*intx * (-1) > 0) && trigger == 0)
			kol = -1;

		while ((a = getchar()) != '\n' && a != EOF){
        	if((a < 48 || a > 57) && a != -1){
        		kol = 1;
			}
        }
	

        if (c == 0 || kol != 0){//некорректный ввод
            printf("\t\t\t\tIncorrect input\n");
        }
		tryagain = 1;       
            
    }
	printf("\t\t\t\tSuccessful input\n\n"); 
	return 0;
}

void input(Matrix* matr, int* eof, int* m, int* n, int* nulls){
	printf("-Enter number of lines: ");
	int kol = 0;
	int trigger = 0;
	getint(m, trigger);
	if (m > 0){
		matr->lines = *m;
		matr->stroki = malloc(*m * sizeof(Line));//выделили память под массив структур
		if (matr->stroki == NULL)
			{printf("Memory allocation faled\n"); exit(1);}
		for(int i = 0; i < matr->lines; i++){
			printf("-Enter size of line %d: ", i+1);
			*n = 0;
			trigger = 0;
			*eof = getint(n, trigger);
			matr->stroki[i].n = *n;//пишу количество элементов в массиве строки

			if (*n != 0)
				matr->stroki[i].arr = malloc(*n * sizeof(int));//выделяю под массив строки память
			else
				matr->stroki[i].arr = NULL + 1;
			if (matr->stroki[i].arr == NULL)
				{printf("Memory allocation faled\n"); exit(1);}
			for (int j = 0; j < *n; j++){
				printf("*Enter element %d of line %d: ", j+1, i+1);
				int elem = 0;
				trigger = 1;
				*eof = getint(&elem, trigger);
				if (elem == 0)
					kol++;
				matr->stroki[i].arr[j] = elem;
			}
			if (kol == *n || *n == 0)
				(*nulls)++;
			kol = 0;
			
		}
	}
}

void output(Matrix* matr){
	for (int i = 0; i < matr->lines; i++){
		printf("%d line: ", i+1);
		if (matr->stroki[i].n != 0){
			for (int j = 0; j < matr->stroki[i].n; j++){
				printf("%d ", matr->stroki[i].arr[j]);
			}
		}
		printf("\n");
	}
}

void erase(Matrix* example){
	for (int i = 0;  i < example->lines; i++){
		if (example->stroki[i].n != 0)
			free(example->stroki[i].arr);
	}
	free(example->stroki);
}

