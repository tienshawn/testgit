#include <stdio.h>

/*
Data types, whose names have the form arr_##name or matrix_##name, are already defined with the following structures:
*/
typedef struct arr_int{
    int* arr;
    int size;
} arr_int;

typedef struct matrix_int {
    arr_int* arr;
    int size;
} matrix_int;
//If the task's output type is one of above types, your output will be scored according to the attributes[size and arr] of the returned object.

int checkSumOfTwo(arr_int a, arr_int b, int c)
{
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < b.size; j++) {
            if (a.arr[i] + b.arr[j] == c) return 1;
        }
    }
    return 0;
}