#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach: Two Pointers (Optimal Solution)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            // Calculate the area formed by the lines at left and right
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            int area = width * minHeight;
            
            // Update the maximum water area
            maxWater = max(maxWater, area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

/*
Time Complexity:
- The algorithm uses two pointers to traverse the array, and each pointer moves at most n times.
- Total Time Complexity: O(n).
  Explanation: Each pointer moves once across the array, resulting in a linear time solution.
Space Complexity: O(1), no extra space is used except for the pointers and the result variable.
*/

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example input

    Solution solution;
    int result = solution.maxArea(height);

    cout << "Maximum water that can be contained: " << result << endl; // Output: 49

    return 0;
}
/*
// Approach: Brute Force (Checking All Pairs)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;

        // Iterate over all pairs of lines using two nested loops
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int width = j - i;
                int minHeight = min(height[i], height[j]);
                maxArea = max(maxArea, width * minHeight);
            }
        }

        return maxArea;
    }
};


Time Complexity:
- The algorithm uses two nested loops to check every possible pair of lines.
- Total Time Complexity: O(n^2).
  Explanation: We check every pair of lines (i, j) where \( i < j \), which results in \( \frac{n(n-1)}{2} \) comparisons.
Space Complexity: O(1), no extra space is used except for variables.

*/
/*
// Approach: Greedy Approach (Max Heights Approach)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        
        // Compute max height from left to right
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }

        // Compute max height from right to left
        maxRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }

        // Compute the maximum area considering max height
        for (int i = 0; i < n; ++i) {
            int minHeight = min(maxLeft[i], maxRight[i]);
            maxArea = max(maxArea, minHeight * (n - i - 1));
        }

        return maxArea;
    }
};


Time Complexity:
- Two loops to compute the max left and right heights, each taking O(n).
- The final loop to compute the maximum area takes O(n).
- Total Time Complexity: O(n).
  Explanation: The time complexity is linear due to three O(n) passes over the array.
Space Complexity: O(n), due to storing the maxLeft and maxRight arrays.

*/
/*
// Approach: Divide and Conquer (Recursive)
class Solution {
public:
    int maxArea(vector<int>& height) {
        return helper(height, 0, height.size() - 1);
    }

    int helper(vector<int>& height, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int width = right - left;
        int minHeight = min(height[left], height[right]);
        int maxArea = width * minHeight;

        if (height[left] < height[right]) {
            maxArea = max(maxArea, helper(height, left + 1, right));
        } else {
            maxArea = max(maxArea, helper(height, left, right - 1));
        }

        return maxArea;
    }
};


Time Complexity:
- The algorithm divides the problem in half recursively, checking each subproblem once.
- Total Time Complexity: O(n \log n).
  Explanation: The recursive division leads to a binary tree structure of depth O(\log n), with each level taking O(n) time.
Space Complexity: O(\log n), for recursion stack due to the recursive nature.

*/