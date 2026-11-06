class Solution:
    def productExceptSelf(self, nums):

        n = len(nums)
        answer = [1] * n

        # Calculate prefix products
        prefix = 1

        for i in range(n):
            answer[i] = prefix
            prefix *= nums[i]

        # Calculate suffix products
        suffix = 1

        for i in range(n - 1, -1, -1):
            answer[i] *= suffix
            suffix *= nums[i]

        return answer


# Main function for local execution
if __name__ == "__main__":

    obj = Solution()

    nums = [1, 2, 3, 4]

    result = obj.productExceptSelf(nums)

    print("Product Except Self:", result)