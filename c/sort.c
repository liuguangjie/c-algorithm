
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
/**函数声明*/

void bubbSort(int*, int);
void insertSort(int*, int);
void selectSort(int*, int);
void xierSort(int*, int);
void format_print(int* , int);
void quickSort(int* , int , int );
void insertDemo2(int*, int);
void select2(int*, int);
void merge(int*, int, int , int);
void mergeSort(int*, int, int);
void baseNumberSort(int* arr, int);
void restZero(int*, int);
int main()
{   
    srand((unsigned) time(NULL));  //用时间做种，每次产生随机数不一样
    int len = 10;
    int i;
    int* arr = (int*)malloc(len * sizeof(int));
    /**生成数组*/
    for (i = 0; i < len; i++)
    {
        arr[i] = rand()>>22 ;
    }
    //int arr[10] = {6,3,4,2,1,7,8,9,0,5};
   // int arr[8] = {1,3,5,2,4,6,8,10};
    printf("原数组\n");
    format_print(arr, len);
    printf("排序后的数组\n");
    //insertDemo2(arr, len);
    //quickSort(arr,0, len - 1);
    //select2(arr,len);
    // {1,3,5,2,4,6,8,10}
    //mergeSort(arr, 0,len - 1);
    baseNumberSort(arr, len);
    format_print(arr, len);
    


    //bubbSort(arr, 10);

    return 0;
}


//基数排序, 非负数
void baseNumberSort(int* arr, int len) {
    int min = INT_MIN;
    int i,j,k,m,n,q;
    for (i=0;i<len;i++) {
        if (arr[i] > min) {
            min = arr[i];
        }
    }
    // 获取最大数的位数
    int bits = 0;
    int nums = 1;
    if (min > 0) {
        while (min>=nums)
        {
            bits++;
            nums *=10;
        }
    }
    // 存放每个位的数组
    int* counts = (int*)malloc(10*sizeof(int));
    restZero(counts, 10);
    // 创建二维数组
    int** table = (int **)malloc(sizeof(int *) * 10);;
    for (i=0;i<10;i++) {
        table[i] = (int *)malloc(sizeof(int) * len);
        for (j=0;j<len;j++) {
            table[i][j] = 0;
        }
    }


    for (i=0,n=1;i < bits;i++,n*=10) {

        for(j=0;j<len;j++) {
            int y = arr[j]/n%10;
            table[y][counts[y]] = arr[j];
            counts[y] ++;
        }
        int index=0;
        
        for (k=0;k<10;k++) {
            if (counts[k] != 0) {
                for(m=0;m<counts[k];m++) {
                    arr[index] = table[k][m];
                    index++;
                }
                counts[k]=0;   
            }
        }

    }



    //printf("%d\n", bits);



}

void restZero(int* arr, int len) {
    int i;
    for(i=0;i<len;i++) {
        arr[i]=0;
    }
}

void mergeSort(int* arr, int low, int high) {
    int middle = (low + high) /2;
    if (low < high) {
        // 处理左边
        mergeSort(arr, low, middle);
        // 处理右边
        mergeSort(arr,middle + 1, high);
        // 归并
        merge(arr, low, middle, high);
    }
}

// 归并排序
void merge(int* arr, int low, int middle, int high) {
    // 用户存储归并后的临时数组
    int len = high - low + 1;
    int* temp = (int*)malloc(len*sizeof(int));
    //记录第一个数组中需要便利的下标
    int i = low;
    // 记录第二个数组总需要便利的下标
    int j = middle + 1;
    // 记录下标
    int index = 0;
    // 遍历两个数组取出最小数字,放入临时变量中
    while (i<=middle&&j<=high)
    {
        if(arr[i] <= arr[j]) {
            //把小的数据放在临时数组中
            temp[index] = arr[i];
            i++;
        } else  {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }

    // 处理多余的数据
    while (j<=high)
    {
        temp[index] = arr[j];
        j++;
        index++;
    }

    while (i<=middle)
    {
        temp[index] = arr[i];
        i++;
        index++;
    }
    
    // 把临时数组中的数据重新存入原数组
    for(int k=0; k < len; k++) {
        arr[k+low] = temp[k];
    }

}

void quickSort(int* arr, int start, int end) {
    if (start < end) {
        int key = arr[start];
    int left = start;
    int right = end;
    //int tm = 0;
    while (left < right)
    {
        while(left < right && arr[right] >= key) {right--;}
        arr[left] = arr[right];
        while(left < right && arr[left] <= key) {left++;}
         arr[right] = arr[left];
        // while(left < right && arr[--right] >= key);
        // while(left < right && arr[++left] <= key);
        // tm = arr[left];
        // arr[left] = arr[right];
        // arr[right] = tm;
        // 交换
    }
    arr[left] = key;
    quickSort(arr, start, left);
    quickSort(arr, left+1, end);
    }
    
}

void format_print(int* arr, int len)
{
    /**如果存在*/
    if (arr != NULL) 
    {
        int i;
        
        for (i = 0; i < len; i++) 
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

}
/**
 * 冒排序
 * 基本思路: 每循环一次都 拿其中的一个数 与数组中的每一个
 * 数对比 如果相比较的数要小那么交换位置
 */
void bubbSort(int* arr, int len)
{
    /**如果存在*/
    if (arr != NULL) 
    {
        
        int t = 0, i = 0, j = 0;
        /** int arr[5] = {40,8,15,18,12}; */
        for( ;i < len - 1; i++)
        {
            for (j =0; j < len-i-1; j++)
            {
                if (arr[j] > arr[j + 1]) 
                {
                    /**交换位置**/
                    t = arr[j];
                    arr[j] = arr[j +1];
                    arr[j+1] = t;
                }
            }

        }
    }
    /**打印*/
    format_print(arr, len);

}

/**
 * 插入排序
 *  基本思路:
 */
void insertSort(int* arr, int len)
{
    if (arr != NULL)
    {
        int i, j, t;
        /** (i = 1) 为前面留一个空位来当插入点*/
        for (i = 1; i < len; i++)
        {   /**临时 记录当前位置的数据*/
            t = arr[i];

            j = i;
            /** j 大于 0  并且 前面的数值比临时的数值大 **/
            while(j > 0 && arr[j - 1] > t)
            {   
                /**往右移 直到找到插入点*/
                arr[j] = arr[j - 1];
                j--;
            }
            /**插入点 就是 j */
            arr[j] = t;

        }
        
    }
    /**打印*/
    format_print(arr, len);
}


void insertDemo2(int* arr, int len){
    int i, j,d=len / 2, t=0;
    for (; d>0;d/= 2) {
        for (i = d; i < len; i+=d) {

            for (j=i-d;j>=0;j-=d) {
                if (arr[j] > arr[j+d]) {
                    t = arr[j];
                    arr[j] = arr[j+d];
                    arr[j+d] = t; 
                }
            }
        }

    }
}

void select2(int* arr, int len) {
    int i,j,k, t;
    for (i=0; i<len; i++) {
        k = i;
        for (j=i+1; j<len; j++) {
            if (arr[k] > arr[j]) {
                k = j;
            }
        }
        // 交换
        t = arr[k];
        arr[k] = arr[i];
        arr[i] = t;
    }
}

/***
 * 选择排序
 * 基本思路: 数组的下标总是指向最小的那个数值 在交换
 */
void selectSort(int* arr, int len)
{
    if (arr != NULL)
    {
        int i, j, min, t;
        for (i = 0; i < len; i++)
        {   
            /**t 总是指向最小的那个数值*/
            min = i;
            for (j = i + 1; j < len; j++)
            {
                if(arr[j] < arr[min])
                {
                    min = j;
                }
            }

            /**交换*/
            t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;

        }
        /**打印*/
        format_print(arr, len);
    }
}

/**
 * 希尔排序
 * 基本思路: 在插入排序上做了优化,
 * 每次计算间隔来做插入排序
 *  {9,1,5,8,3,7,6,0,2,4};
 */

void xierSort(int* arr, int len)
{
    if (arr != NULL)
    {
        
        /**计算最大间隔*/
        int h = 1;
        while(h < len / 3) {
            h = h * 3 + 1;
        }

        int i, j, t;
        while(h > 0) {
            for (i = h; i < len; i++) 
            {
                t = arr[i];
                j = i;
                /** j > h - 1; 大于间隔*/
                while(j > h - 1 && arr[j - h] > t)
                {
                    /**右移*/
                    arr[j] = arr[j - h];
                    j = j - h;
                }
                /**插入点*/
                arr[j] = t;
            }
            
            
            /**减小间隔*/
            h = (h - 1) / 3;
        }
        /**打印*/
        format_print(arr, len);
    }
}
