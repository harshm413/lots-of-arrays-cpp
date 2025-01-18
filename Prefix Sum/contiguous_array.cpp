#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach: Prefix Sum with Hash Map
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> countMap; // Map to store the first occurrence of each count
        countMap[0] = -1; // Initialize with count 0 at index -1
        int maxLength = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            // Update count: +1 for 1, -1 for 0
            count += (nums[i] == 1 ? 1 : -1);

            if (countMap.find(count) != countMap.end()) {
                // If count is found, calculate the length of the subarray
                maxLength = max(maxLength, i - countMap[count]);
            } else {
                // Otherwise, store the first occurrence of this count
                countMap[count] = i;
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
    vector<int> nums = {0, 1, 0}; // Example input

    Solution solution;
    int result = solution.findMaxLength(nums);

    cout << "Maximum length of contiguous subarray with equal number of 0s and 1s: " << result << endl; // Output: 2

    return 0;
}

/*
// Approach: Brute Force
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        // Iterate over all subarrays
        for (int i = 0; i < n; ++i) {
            int countZero = 0, countOne = 0;
            for (int j = i; j < n; ++j) {
                // Update counts based on the current element
                if (nums[j] == 0) {
                    countZero++;
                } else {
                    countOne++;
                }

                // Check if counts are equal
                if (countZero == countOne) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }
};

Time Complexity:
- Outer loop runs for O(n), iterating over all starting indices.
- Inner loop runs for O(n), calculating counts for subarrays starting at each index.
- Total Time Complexity: O(n^2).
  Explanation: For each starting index, we iterate over the remaining elements to find valid subarrays.
Space Complexity: O(1), as no additional data structures are used.

*/