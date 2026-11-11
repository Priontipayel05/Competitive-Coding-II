class Solution:
    def searchInsert(self, nums, target):

        low = 0
        high = len(nums) - 1

        while low <= high:

            mid = low + (high - low) // 2

            if nums[mid] == target:
                return mid

            elif nums[mid] < target:
                low = mid + 1

            else:
                high = mid - 1

        return low


# Main function for local execution
if __name__ == "__main__":

    obj = Solution()

    nums = [1, 3, 5, 6]
    target = 5

    result = obj.searchInsert(nums, target)

    print("Search Insert Position:", result)