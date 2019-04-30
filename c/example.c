#include <stdio.h>
#include "sort.h"

/***
 好久之前面试遇到的笔试题:
 int arr[10] = {5, 4, 8, 4, 8, 5, 8, 6, 4, 8};
 计算每个元素重复的次数, 最后 根据次数排序: 输出结果如下
 数字 6 出现 1 次
 数字 5 出现 2 次
 数字 4 出现 3 次
 数字 8 出现 4 次
 */
void toHeavy();

int main()
{
    toHeavy();
    return 0;
}

/**
 不用类库实现
 基本思路是用数组加 结构体
*/
typedef struct Map 
{
    int key; //关键字
    int count; //次数
} Map;

void toHeavy()
{
    int orig[10] = {5, 4, 8, 4, 8, 5, 8, 6, 4, 8}; 
    
    int i, j, index = 1;
    
    Map map[4];
    int arr[4] = {0, 0, 0, 0};
    /**排序*/
    bubbSort(orig, 10);
    
    arr[0] = orig[0];
    /**去重*/
    for (j = 1; j < 10; j++)
    {
        if (orig[j - 1] != orig[j])
        {
            arr[index++] = orig[j];
        }
    }
    /**赋值*/
    for(j = 0; j < 4; j++)
    {
        map[j].key = arr[j];
        map[j].count = 0;
    }

    /**计算次数*/
    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < 4; i++)
        {
            if (orig[j] == map[i].key)
            {
                map[i].count++;
            }
        }
    }

    /**排序次数*/
    Map mp;
    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (map[i].count > map[j].count)
            {
                mp = map[i];
                map[i] = map[j];
                map[j] = mp;
            }
        }
    }
    /**打印*/
    for (j = 0; j < 4; j++)
    {
        printf("数字 %d 出现 %d 次\n", map[j].key, map[j].count);
    }



}






