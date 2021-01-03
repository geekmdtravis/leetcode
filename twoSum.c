#include <stdio.h>
#include <stdlib.h>
#include "twoSum.h"

int main () {
    const int target = 10;
    int nums[NUMS_COUNT] = { 2, 5, 5, 11 };
    int returnSize;

    int *result = twoSum(nums, NUMS_COUNT, target, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("twoSum[%d]: %d\n", i, result[i]);
    }

    free(result);

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize){
    *returnSize = 2;
    int *returnValues = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                returnValues[0] = i;
                returnValues[1] = j;
            }
        }
    }
    
    return returnValues;
}