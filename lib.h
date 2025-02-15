#ifndef LIB_H
#define LIB_H

typedef struct Line{//строка матрицы
    int n;
    int* arr;
}Line;


typedef struct Matrix{//сама матрица
    int lines;
    Line* stroki;
}Matrix;

typedef struct Border{
    int indexpos;
    int pos;
    int indexneg;
    int neg;
}Border;

int getint(int*, int);//ввод целого положительного числа для m, n
void input(Matrix*, int*, int*, int*, int*);//заполнение матрицы
void output(Matrix*);//вывод матрицы
void erase(Matrix*);//освобождение памяти под матрицу
void task(Matrix*, Matrix*, int*, int*, Border*);//индивиидуальное задание
void createline(Matrix*, Matrix*, int, Border*, int);//создание линии
void minmax(int*, int*, Border*);//поиск максимального и минимального элемента

#endif