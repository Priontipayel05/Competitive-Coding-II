
import java.util.Stack;

public class Main {

    static class Solution {

        public int largestRectangleArea(int[] heights) {
            Stack<Integer> st = new Stack<>();
            int maxArea = 0;
            int n = heights.length;

            for (int i = 0; i <= n; i++) {
                int currentHeight = (i == n) ? 0 : heights[i];

                while (!st.empty() &&
                       currentHeight < heights[st.peek()]) {

                    int height = heights[st.pop()];

                    int width = st.empty() ? i : i - st.peek() - 1;

                    maxArea = Math.max(maxArea, height * width);
                }

                if (i < n) {
                    st.push(i);
                }
            }

            return maxArea;
        }
    }

    public static void main(String[] args) {
        Solution obj = new Solution();

        int[] heights = {2, 1, 5, 6, 2, 3};

        int result = obj.largestRectangleArea(heights);

        System.out.println("Largest Rectangle Area: " + result);
    }
}
