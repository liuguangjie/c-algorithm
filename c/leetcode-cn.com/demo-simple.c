#include <stdio.h>
#include "../sort.h"

int removeDuplicates(int* nums, int numsSize) {


	/** 在排好顺序的情况下 nums = [0,0,1,1,1,2,2,3,3,4]*/
	int i, j, k;
		    
	int len = 1;
	
	for (i = 1; i < numsSize; i++)
	{
		if (nums[i - 1] != nums[i])
		{
			++len;
		}
	}

	return len;
}


/***
两数之和
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
int* toArrayIndex(int* arr, int len, int target)
{
	int i, j;
	static int index[2] = {-1, -1}; 
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] + arr[j] == target)
			{
				index[0] = i;
				index[1] = j;
			}
		}
	}

	return index;
}


int main()
{
	// int nums[] = {0,1,1,1,1,2,2,3,3,4};
	// int a = removeDuplicates(nums, 10);
	// //format_print(nums, 10);
	// printf("去重过后的元素个数 %d \n", a);


	int arr[4] = {2, 7, 11, 15};

	int* arrIndex = toArrayIndex(arr, 4, 26);
	
	format_print(arrIndex, 2);

	return 0;
}


