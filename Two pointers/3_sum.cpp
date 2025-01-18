#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach: Sorting + Two Pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the array for two-pointer approach

        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements for 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicates for 'left' and 'right'
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};

/*
Time Complexity:
- Sorting the array takes O(n \log n).
- The outer loop runs for O(n), and for each element, the two-pointer technique takes O(n).
- Total Time Complexity: O(n^2).
  Explanation: Sorting takes O(n \log n), and the two-pointer technique takes O(n) for each element.
Space Complexity: O(1) for the pointers and other variables, excluding the result array.
*/

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // Example input

    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    cout << "Unique triplets that sum to zero: " << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
/*
// Approach: Brute Force (Checking All Triplets)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        // Iterate over all triplets using three nested loops
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return result;
    }
};


Time Complexity:
- The algorithm uses three nested loops, iterating over every combination of triplets.
- Total Time Complexity: O(n^3).
  Explanation: The three nested loops result in checking every triplet in the array.
Space Complexity: O(1), as no additional data structures (except the result) are used.

*/