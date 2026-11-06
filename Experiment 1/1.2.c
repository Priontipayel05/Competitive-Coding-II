#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int nums[], int numsSize, int* returnSize) {

    *returnSize = numsSize;

    int* answer = (int*)malloc(numsSize * sizeof(int));

    if (answer == NULL && numsSize > 0) {
        *returnSize = 0;
        return NULL;
    }

    int prefix = 1;

    // Calculate prefix products
    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;

    // Calculate suffix products
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}

int main() {

    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int returnSize;

    int* result = productExceptSelf(nums, n, &returnSize);

    printf("Product Except Self: ");

    if (result != NULL) {
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", result[i]);
        }
    }

    printf("\n");

    free(result);

    return 0;
}