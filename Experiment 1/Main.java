import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {

        if (k <= 0) {
            return false;
        }

        Set<Integer> window = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {

            if (window.contains(nums[i])) {
                return true;
            }

            window.add(nums[i]);

            if (window.size() > k) {
                window.remove(nums[i - k]);
            }
        }

        return false;
    }
}

public class Main {
    public static void main(String[] args) {

        Solution obj = new Solution();

        int[] nums = {1, 2, 3, 1};
        int k = 3;

        boolean result = obj.containsNearbyDuplicate(nums, k);

        System.out.println(result);
    }
}