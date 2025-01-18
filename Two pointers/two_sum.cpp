#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach: Using Hash Map for Efficient Lookup
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // Map to store number and its index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If complement exists in the map, return its index and current index
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Store the current number with its index
            numMap[nums[i]] = i;
        }

        return {}; // This line won't be reached as the problem guarantees exactly one solution
    }
};

/*
Time Complexity:
- The algorithm iterates through the array once and performs constant-time operations (hash map lookup, insert) for each element.
- Total Time Complexity: O(n).
  Explanation: We process each element in the array only once, and hash map operations are O(1) on average.
Space Complexity: O(n), for storing elements in the hash map.
*/

int main() {
    vector<int> nums = {2, 7, 11, 15}; // Example input
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    cout << "Indices of the two numbers that add up to " << target << ": ";
    cout << result[0] << " " << result[1] << endl; // Output: 0 1

    return 0;
}

/*
// Approach: Brute Force (Checking All Pairs)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Iterate through all pairs to find the solution
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // Return indices of the pair that adds up to target
                }
            }
        }
        
        return {}; // Return empty if no pair is found
    }
};


Time Complexity:
- The algorithm iterates through all pairs, meaning it has two nested loops.
- Total Time Complexity: O(n^2).
  Explanation: For each element, we check every other element for a valid pair.
Space Complexity: O(1), as no extra space is used.
*/
/*
// Approach: Sorting and Two Pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums(n);
        
        // Store elements along with their original indices
        for (int i = 0; i < n; ++i) {
            indexedNums[i] = {nums[i], i};
        }
        
        // Sort the array
        sort(indexedNums.begin(), indexedNums.end());

        int left = 0, right = n - 1;
        
        // Use two-pointer approach to find the two sum
        while (left < right) {
            int currentSum = indexedNums[left].first + indexedNums[right].first;
            
            if (currentSum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            }
            else if (currentSum < target) {
                ++left;
            }
            else {
                --right;
            }
        }
        
        return {}; // Return empty if no pair is found
    }
};

Time Complexity:
- Sorting the array takes O(n \log n), and the two-pointer traversal takes O(n).
- Total Time Complexity: O(n \log n).
  Explanation: Sorting takes O(n \log n), followed by a single pass through the array using two pointers.
Space Complexity: O(n), as we are storing the original indices alongside the numbers.
*/
/*
// Approach: Using Binary Search (After Sorting)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums(n);
        
        // Store elements along with their original indices
        for (int i = 0; i < n; ++i) {
            indexedNums[i] = {nums[i], i};
        }
        
        // Sort the array
        sort(indexedNums.begin(), indexedNums.end());
        
        // Iterate through each element and use binary search for the complement
        for (int i = 0; i < n; ++i) {
            int complement = target - indexedNums[i].first;
            int left = i + 1, right = n - 1;
            
            // Binary search for the complement
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (indexedNums[mid].first == complement) {
                    return {indexedNums[i].second, indexedNums[mid].second};
                }
                else if (indexedNums[mid].first < complement) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return {}; // Return empty if no pair is found
    }
};


Time Complexity:
- Sorting the array takes O(n \log n), and for each element, we perform binary search, which takes O(log n).
- Total Time Complexity: O(n \log n).
  Explanation: Sorting takes O(n \log n), and binary search for each element takes O(log n).
Space Complexity: O(n), as we are storing the original indices alongside the numbers.

*/