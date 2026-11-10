class Solution:
    def search(self, nums, target):

        low = 0
        high = len(nums) - 1

        while low <= high:

            mid = low + (high - low) // 2

            # Check if target is found
            if nums[mid] == target:
                return mid

            # Check if left half is sorted
            if nums[low] <= nums[mid]:

                if nums[low] <= target < nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1

            # Right half is sorted
            else:

                if nums[mid] < target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1

        return -1


# Main function for local execution
if __name__ == "__main__":

    obj = Solution()

    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 0

    result = obj.search(nums, target)

    print("Target Element Index:", result)