#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount; // Map to store the frequency of remainders
        remainderCount[0] = 1; // Base case: a sum divisible by k from the beginning
        int count = 0;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;

            // Compute remainder
            int remainder = currentSum % k;
            // Handle negative remainders to make them positive
            if (remainder < 0) {
                remainder += k;
            }

            // If the remainder has been seen before, it contributes to the count
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }

            // Increment the frequency of the remainder
            remainderCount[remainder]++;
        }

        return count;
    }
};

/*
Time Complexity:
- Iterating over the array takes O(n).
- Each remainder lookup or insertion in the hash map takes O(1) on average.
- Total Time Complexity: O(n).
  Explanation: The hash map allows for constant-time lookups and insertions of remainders.
Space Complexity: O(k), as the hash map stores at most k unique remainders.
*/

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1}; // Example input
    int k = 5;

    Solution solution;
    int result = solution.subarraysDivByK(nums, k);

    cout << "Number of subarrays divisible by " << k << ": " << result << endl; // Output: 7

    return 0;
}
/*
// Approach: Brute Force
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Iterate over all subarrays
        for (int i = 0; i < n; ++i) {
            int currentSum = 0;
            for (int j = i; j < n; ++j) {
                currentSum += nums[j]; // Calculate the sum of the current subarray

                // Check if the sum is divisible by k
                if (currentSum % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};


Time Complexity:
- Outer loop runs for O(n), iterating over all starting indices.
- Inner loop runs for O(n), calculating sums for subarrays starting at each index.
- Total Time Complexity: O(n^2).
  Explanation: For each starting index, we iterate over the remaining elements to calculate subarray sums.
Space Complexity: O(1), as no additional data structures are used.

*/