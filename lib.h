typedef struct Line{//строка матрицы
    int n;
    int* arr;
}Line;

typedef struct Matrix{//сама матрица
    int lines;
    Line* stroki;
}Matrix;

int getintmn(int*);//ввод целого положительного числа для m, n
int getint(int*);//ввод целого числа 
void input(Matrix*, int*);//заполнение матрицы
void output(Matrix*);//вывод матрицы
void erase(Matrix*);//освобождение памяти под матрицу


/*int* subarray(Line* str);//выделение подмассива из строки*/