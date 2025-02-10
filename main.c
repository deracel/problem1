#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib.h"

int main(){
    Matrix matr = {0, NULL};
    /*int* ans = NULL;*/
    int eof = 0;
    input(&matr, &eof);
    if (eof != 1)
        output(&matr);
    erase(&matr);
    
    /*if (input(&matr) == 0){
        printf("%s\n, End of file occured");
        return 0;
    }*/
   return 0;

}





