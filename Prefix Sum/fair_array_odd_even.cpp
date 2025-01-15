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

/*
// Approach: Brute Force
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int count = 0;

        // Iterate over all indices
        for (int i = 0; i < nums.size(); ++i) {
            int evenSum = 0, oddSum = 0;

            // Calculate sums for the array excluding index i
            for (int j = 0; j < nums.size(); ++j) {
                if (j == i) continue;
                if (j < i) {
                    if (j % 2 == 0) evenSum += nums[j];
                    else oddSum += nums[j];
                } else {
                    if ((j - 1) % 2 == 0) evenSum += nums[j];
                    else oddSum += nums[j];
                }
            }

            // Check if the sums are equal
            if (evenSum == oddSum) {
                count++;
            }
        }

        return count;
    }
};


Time Complexity:
- Outer loop runs for O(n), iterating over all indices.
- Inner loop runs for O(n), calculating the sums for each removal.
- Total Time Complexity: O(n^2), where n is the size of the array.
  Explanation: For each index, we recalculate the sums from scratch.
Space Complexity: O(1), as no additional data structures are used.

*/