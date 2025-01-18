#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach: Prefix Sum with Hash Map
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumMap; // Map to store the first occurrence of prefix sums
        prefixSumMap[0] = -1; // Initialize to handle subarray starting from index 0
        int maxLength = 0;
        int currentSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i]; // Update the running prefix sum

            // Check if there's a subarray ending at index i that sums to k
            if (prefixSumMap.find(currentSum - k) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[currentSum - k]);
            }

            // Store the first occurrence of the current sum
            if (prefixSumMap.find(currentSum) == prefixSumMap.end()) {
                prefixSumMap[currentSum] = i;
            }
        }

        return maxLength;
    }
};

/*
Time Complexity:
- Iterating over the array takes O(n).
- Each prefix sum lookup or insertion in the hash map takes O(1) on average.
- Total Time Complexity: O(n).
  Explanation: The hash map allows for constant-time lookups and insertions.
Space Complexity: O(n), as the hash map stores prefix sums and their indices.
*/

int main() {
    vector<int> nums = {1, -1, 5, -2, 3}; // Example input
    int k = 3;

    Solution solution;
    int result = solution.maxSubArrayLen(nums, k);

    cout << "Maximum size subarray with sum " << k << ": " << result << endl; // Output: 4

    return 0;
}

/*
// Approach: Brute Force
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLength = 0;

        // Iterate over all subarrays
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            for (int j = i; j < n; ++j) {
                currentSum += nums[j]; // Calculate the sum of the current subarray
                if (currentSum == k) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }
};

Time Complexity:
- Outer loop runs for O(n), iterating over all starting indices.
- Inner loop runs for O(n), calculating sums for subarrays starting at each index.
- Total Time Complexity: O(n^2).
  Explanation: For each starting index, we iterate over the remaining elements to calculate subarray sums.
Space Complexity: O(1), as no additional data structures are used.

*/