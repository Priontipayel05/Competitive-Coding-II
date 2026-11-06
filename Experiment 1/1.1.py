class Solution:
    def containsNearbyDuplicate(self, nums, k):

        if k <= 0:
            return False

        window = set()

        for i in range(len(nums)):

            # Check whether the current element already exists
            if nums[i] in window:
                return True

            # Add the current element
            window.add(nums[i])

            # Remove the element outside the sliding window
            if i >= k:
                window.remove(nums[i - k])

        return False


# Main function for local execution
if __name__ == "__main__":

    obj = Solution()

    nums = [1, 2, 3, 1]
    k = 3

    result = obj.containsNearbyDuplicate(nums, k)

    print(result)