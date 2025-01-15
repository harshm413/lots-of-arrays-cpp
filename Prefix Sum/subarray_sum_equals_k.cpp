#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
// Approach: Brute Force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int currentSum = 0;
            for (int j = i; j < nums.size(); ++j) {
                currentSum += nums[j]; // Calculate the sum of subarray [i, j]
                if (currentSum == k) {
                    count++; // Increment count if sum matches k
                }
            }
        }
        return count;
    }
};

Time Complexity:
- Outer loop runs for O(n).
- Inner loop runs for O(n) in the worst case for each iteration of the outer loop.
- Total Time Complexity: O(n^2), where n is the size of the array.
  Explanation: For every starting point, we calculate the sum for all possible subarrays starting from that point.
Space Complexity: O(1), as no additional space is used.
*/

// Approach: Prefix Sum Array with Hash Map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount; // To store prefix sum frequencies
        prefixSumCount[0] = 1; // Base case: one way to get sum = 0
        int currentSum = 0;
        int count = 0;

        for (int num : nums) {
            currentSum += num; // Update the current prefix sum
            // Check if (currentSum - k) exists in the map
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }
            // Update the frequency of the current prefix sum
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};

/*
Time Complexity:
- Single pass through the array: O(n).
  Explanation: Each element is processed once, and hash map operations (insert/find) take O(1) on average.
Space Complexity: O(n), for storing the prefix sums in the hash map.
*/

int main() {
    vector<int> nums = {1, 1, 1}; // Example input
    int k = 2;

    Solution solution;
    int result = solution.subarraySum(nums, k);

    cout << "Number of subarrays with sum equal to " << k << ": " << result << endl; // Output: 2

    return 0;
}


/*
// Approach: Cumulative Prefix Sum (Inefficient Compared to Hash Map)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> prefixSums(nums.size() + 1, 0);

        // Compute prefix sums
        for (int i = 0; i < nums.size(); ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        // Check all subarrays
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (prefixSums[j + 1] - prefixSums[i] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};


Time Complexity:
- Preprocessing: O(n), to calculate the prefix sums.
- Subarray Check: O(n^2), to iterate over all subarray pairs.
- Total Time Complexity: O(n^2).
  Explanation: Though prefix sums reduce repeated calculations, we still check all subarrays explicitly.
Space Complexity: O(n), for storing prefix sums.
*/

/*
// Approach: Sliding Window (Non-Negative Numbers Only)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int left = 0, right = 0;
        int currentSum = 0;

        while (right < nums.size()) {
            currentSum += nums[right];
            while (currentSum > k && left <= right) {
                currentSum -= nums[left++];
            }
            if (currentSum == k) {
                count++;
            }
            right++;
        }

        return count;
    }
};

Time Complexity:
- O(n), where n is the size of the array.
  Explanation: Each element is processed at most twice (once when added to the current sum and once when removed).
Space Complexity: O(1), as no additional space is used.

*/