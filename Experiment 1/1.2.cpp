#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> answer(n, 1);

        // Calculate prefix products
        int prefix = 1;

        for (int i = 0; i < n; ++i) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Calculate suffix products
        int suffix = 1;

        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = obj.productExceptSelf(nums);

    cout << "Product Except Self: ";

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}