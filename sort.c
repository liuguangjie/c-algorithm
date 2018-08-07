
#include <stdio.h>

/**函数声明*/
void bubbSort(int* arr, int len);
void format_print(int* arr, int len);

int main()
{
    
    int arr[5] = {40,8,15,18,12};
    bubbSort(arr, 5);
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