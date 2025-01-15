#include <iostream>
#include <vector>
using namespace std;

/*
// Approach: Brute Force
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int leftSum = 0, rightSum = 0;

            // Calculate the sum of elements on the left of index i
            for (int j = 0; j < i; ++j) {
                leftSum += nums[j];
            }

            // Calculate the sum of elements on the right of index i
            for (int j = i + 1; j < nums.size(); ++j) {
                rightSum += nums[j];
            }

            // Check if leftSum equals rightSum
            if (leftSum == rightSum) {
                return i; // Found the pivot index
            }
        }

        return -1; // No pivot index found
    }
};


Time Complexity:
- Outer loop runs for O(n), where n is the size of the array.
- For each iteration, two inner loops calculate the left and right sums, each taking O(n) in the worst case.
- Total Time Complexity: O(n^2).
  Explanation: The brute force approach explicitly calculates left and right sums for every index.
Space Complexity: O(1), as no additional data structures are used.

*/

// Approach: Optimized Using Total Sum(Sliding Window)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Traverse the array and check the pivot condition
        for (int i = 0; i < nums.size(); ++i) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i; // Found the pivot index
            }
            leftSum += nums[i];
        }

        return -1; // No pivot index found
    }
};

/*
Time Complexity:
- Calculating the total sum takes O(n).
- Traversing the array to check the pivot condition takes O(n).
- Total Time Complexity: O(n).
  Explanation: The total sum is precomputed, and each element is processed only once to maintain leftSum.
Space Complexity: O(1), as no additional data structures are used.
*/

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6}; // Example input

    Solution solution;
    int pivot = solution.pivotIndex(nums);

    if (pivot != -1) {
        cout << "Pivot index: " << pivot << endl; // Output: 3
    } else {
        cout << "No pivot index found" << endl;
    }

    return 0;
}

/*
// Approach: Two-Pass Using Prefix Sums
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSums(n, 0);

        // Compute prefix sums
        prefixSums[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSums[i] = prefixSums[i - 1] + nums[i];
        }

        // Traverse the array and check the pivot condition
        for (int i = 0; i < n; ++i) {
            int leftSum = (i == 0) ? 0 : prefixSums[i - 1];
            int rightSum = prefixSums[n - 1] - prefixSums[i];
            if (leftSum == rightSum) {
                return i; // Found the pivot index
            }
        }

        return -1; // No pivot index found
    }
};


Time Complexity:
- Calculating prefix sums takes O(n).
- Traversing the array to check the pivot condition takes O(n).
- Total Time Complexity: O(n).
  Explanation: Prefix sums allow us to compute left and right sums in constant time for each index.
Space Complexity: O(n), to store the prefix sums.

*/