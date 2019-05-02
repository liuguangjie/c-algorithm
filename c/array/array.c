#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArr(int*, int);
int main()
{

    //printf("%d\n", CHAR_BIT);
    int a[5] = {1,2,3,4,5};
    printArr(a, 5);
    int *arr ;
    int len = sizeof(a) / sizeof(int) - 1;
    arr = (int*)(calloc(len, sizeof(int)));

    int i,index = 2; 
    for (i = 0; i < len; i++) {
        if (i < index) {
            arr[i] = a[i];
        } else {
            arr[i] = a[i+1];
        }
    }
    printArr(arr, 4);
    printf("\n");


    //printf("%d\n", sizeof(a) / sizeof(int));

    free(arr);//释放第一维指针
    return 0;
}

void printArr(int* arr,int len) {

    int i;
    
    for (i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
 }