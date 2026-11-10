#include <stdio.h>

int search(int nums[], int numsSize, int target) {

    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // Check if target is found
        if (nums[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        if (nums[low] <= nums[mid]) {

            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right half is sorted
        else {

            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    int target = 0;

    int result = search(nums, n, target);

    printf("Target Element Index: %d\n", result);

    return 0;
}