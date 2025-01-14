#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

int main() {
    vector<int> nums = {1, 1, 1}; // Example input
    int k = 2;

    Solution solution;
    int result = solution.subarraySum(nums, k);

    cout << "Number of subarrays with sum equal to " << k << ": " << result << endl; // Output: 2

    return 0;
}
