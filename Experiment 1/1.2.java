import java.util.Arrays;

class Solution {
    public int[] productExceptSelf(int[] nums) {

        int n = nums.length;
        int[] answer = new int[n];

        // Calculate prefix products
        int prefix = 1;

        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Calculate suffix products
        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args) {

        Solution obj = new Solution();

        int[] nums = {1, 2, 3, 4};

        int[] result = obj.productExceptSelf(nums);

        System.out.println("Product Except Self: " + Arrays.toString(result));
    }
}