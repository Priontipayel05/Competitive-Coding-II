
class Solution:

    def largestRectangleArea(self, heights):
        st = []
        maxArea = 0
        n = len(heights)

        for i in range(n + 1):
            currentHeight = 0 if i == n else heights[i]

            while st and currentHeight < heights[st[-1]]:
                height = heights[st.pop()]

                width = i if not st else i - st[-1] - 1

                maxArea = max(maxArea, height * width)

            if i < n:
                st.append(i)

        return maxArea


if __name__ == "__main__":
    obj = Solution()

    heights = [2, 1, 5, 6, 2, 3]

    result = obj.largestRectangleArea(heights)

    print("Largest Rectangle Area:", result)
