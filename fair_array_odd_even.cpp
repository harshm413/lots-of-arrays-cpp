#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixEven(n + 1, 0), prefixOdd(n + 1, 0);

        // Compute prefix sums for even and odd indices
        for (int i = 0; i < n; ++i) {
            prefixEven[i + 1] = prefixEven[i];
            prefixOdd[i + 1] = prefixOdd[i];
            if (i % 2 == 0) {
                prefixEven[i + 1] += nums[i];
            } else {
                prefixOdd[i + 1] += nums[i];
            }
        }

        int count = 0;

        // Check each index if removing it makes the array fair
        for (int i = 0; i < n; ++i) {
            int leftEven = prefixEven[i];
            int leftOdd = prefixOdd[i];
            int rightEven = prefixOdd[n] - prefixOdd[i + 1];
            int rightOdd = prefixEven[n] - prefixEven[i + 1];

            if (leftEven + rightEven == leftOdd + rightOdd) {
                ++count;
            }
        }

        return count;
    }
};

int main() {
    vector<int> nums = {2, 1, 6, 4}; // Example input

    Solution solution;
    int result = solution.waysToMakeFair(nums);

    cout << "Number of ways to make the array fair: " << result << endl; // Output: 1

    return 0;
}
