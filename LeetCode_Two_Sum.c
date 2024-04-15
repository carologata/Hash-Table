#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int i;
    int j;
    int *returnNums;

    i = 0;
    *returnSize = 2;
    returnNums = malloc(2 * sizeof(int)); 
    while(i < numsSize)
    {
        j = i + 1;
        while(j < numsSize)
        {
            if(nums[i] + nums[j] == target)
            {
                returnNums[0] = i;
                returnNums[1] = j;
            }
            j++;
        }
        i++;
    }
    return (returnNums);
}

/* #include <stdio.h>

int main(void)
{
  int i;
  int numsSize = 4;
  int nums[4] = {-3,4,3,90};
  int target;
  int returnSize;
  int *returnNums;
  
  returnSize = 0;
  target = 0;
  returnNums = twoSum(nums, numsSize, target, &returnSize);
  printf("[%d, %d]\n", returnNums[0], returnNums[1]);
} */