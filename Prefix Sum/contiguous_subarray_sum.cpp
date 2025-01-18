#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach: Prefix Sum with Hash Map
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap; // Maps remainder to its index
        remainderMap[0] = -1; // To handle cases where the subarray starts from index 0
        int cumulativeSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            cumulativeSum += nums[i];
            int remainder = cumulativeSum % k;

            // Handle negative remainders to ensure they're always positive
            if (remainder < 0) {
                remainder += k;
            }

            if (remainderMap.find(remainder) != remainderMap.end()) {
                // Check if the subarray length is at least 2
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                // Store the first occurrence of this remainder
                remainderMap[remainder] = i;
            }
        }

        return false;
    }
};

/*
Time Complexity:
- The algorithm iterates through the array once, performing O(1) operations for each element.
- Total Time Complexity: O(n).
  Explanation: The hash map allows for constant time lookups and insertions, making this a linear solution.
Space Complexity: O(k) in the worst case, where k is the number of unique mod values stored in the map.
*/

int main() {
    vector<int> nums = {23, 2, 4, 6, 7}; // Example input
    int k = 6;

    Solution solution;
    bool result = solution.checkSubarraySum(nums, k);

    cout << "Does the array have a contiguous subarray with a sum that is a multiple of " << k << "? ";
    cout << (result ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
/*
// Approach: Brute Force (Checking All Subarrays)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // Iterate over all subarrays with size >= 2
        for (int i = 0; i < n; ++i) {
            int sum = nums[i];
            for (int j = i + 1; j < n; ++j) {
                sum += nums[j];
                // Check if the sum is a multiple of k
                if (k == 0) {
                    if (sum == 0) return true;
                } else {
                    if (sum % k == 0) return true;
                }
            }
        }

        return false; // No valid subarray found
    }
};


Time Complexity:
- Outer loop runs O(n), and inner loop runs up to O(n) for each iteration of the outer loop.
- Total Time Complexity: O(n^2).
  Explanation: We compute the sum of all subarrays starting from every index.
Space Complexity: O(1), no extra space is used except variables.

*/