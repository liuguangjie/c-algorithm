
#include <stdio.h>

/**函数声明*/
void bubbSort(int*, int);
void insertSort(int*, int);
void selectSort(int*, int);
void format_print(int* , int);

int main()
{
    
    int arr[5] = {40,8,15,18,12};
    selectSort(arr, 5);
    return 0;
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
            for (j = i + 1; j < len; j++)
            {
                if (arr[i] > arr[j]) 
                {
                    /**交换位置**/
                    t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
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
