#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum < 0) {
                currentSum = 0; // Reset the sum if it's negative
            }
            currentSum += num;
            maxSum = max(maxSum, currentSum); // Update maxSum if currentSum is larger
        }

        return maxSum;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input

    Solution solution;
    int result = solution.maxSubArray(nums);

    cout << "Maximum subarray sum: " << result << endl; // Output: 6

    return 0;
}
