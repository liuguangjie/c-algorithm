#include <stdio.h>

/**
 给定一个包含 n 个整数的数组 nums，
 判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
 找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/
int main()
{
    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int arr[2][3];
    int i, j, k, index = 0;
    int len = 6;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            for (k = j + 1; k < len; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    arr[index][0] = nums[i];
                    arr[index][1] = nums[j];
                    arr[index][2] = nums[k];
                    index++;
                }

            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d   ", arr[i][j]);
        }
        printf("\n");
        
    }


}

