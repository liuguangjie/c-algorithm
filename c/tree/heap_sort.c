#include <stdio.h>

//调整大顶堆
void maxHeap(int*,int,int);
void p(int*);
void heapSort(int*,int);
int main()
{
    int arr[9] = {9,6,8,7,0,1,10,4,2};
    p(arr);
    heapSort(arr,9);
    p(arr);
    return 0;
}
void p(int* arr) {
    int i;
    int index = 8;
    printf("[");
    for(i=0;i<index;i++) {
        printf("%d, ",arr[i]);
    }
    printf("%d",arr[index]);
    printf("]\n");
}
void heapSort(int* arr,int len) {
    int i;
    int start = (len-1)/ 2;
    for (i=start;i>=0;i--) {
        maxHeap(arr,len,i);
    }

    for (i=len-1;i>0;i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i]=t;
        maxHeap(arr,i,0);
    }
}
void maxHeap(int* arr, int size, int index) {
    // 左子树
    int left = 2*index + 1;
    // 右子树
    int right = 2*index + 2;

    int max = index;

    if (left < size && arr[left] > arr[max]) {
        max = left;
    }

    if (right < size && arr[right] > arr[max]) {
        max = right; 
    }

    //  交换位置
    if (max != index) {
        int t = arr[max];
        arr[max] = arr[index];
        arr[index] = t;
        //考虑还有 下一个子树所以还要递归下去
        maxHeap(arr, size, max);
    }


}



/**
 1.把数组转成大顶堆

 */