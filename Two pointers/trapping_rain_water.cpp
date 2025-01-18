#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int waterTrapped = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                // Process the left side
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    waterTrapped += leftMax - height[left];
                }
                left++;
            } else {
                // Process the right side
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    waterTrapped += rightMax - height[right];
                }
                right--;
            }
        }

        return waterTrapped;
    }
};

/*
Time Complexity:
- The two pointers traverse the array once.
- Total Time Complexity: O(n).
  Explanation: Linear time is achieved as each bar is processed once.
Space Complexity: O(1), no extra space is used except for variables.
*/

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // Example input

    Solution solution;
    int result = solution.trap(height);

    cout << "Total water trapped: " << result << endl; // Output: 6

    return 0;
}
/*
// Approach: Brute Force
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        // Iterate through each bar and calculate trapped water
        for (int i = 0; i < n; ++i) {
            int maxLeft = 0, maxRight = 0;

            // Find the maximum height to the left of the current bar
            for (int j = 0; j <= i; ++j) {
                maxLeft = max(maxLeft, height[j]);
            }

            // Find the maximum height to the right of the current bar
            for (int j = i; j < n; ++j) {
                maxRight = max(maxRight, height[j]);
            }

            // Water trapped at the current bar is determined by the smaller of the two max heights
            totalWater += min(maxLeft, maxRight) - height[i];
        }

        return totalWater;
    }
};


Time Complexity:
- The outer loop runs O(n), and for each element, we calculate maxLeft and maxRight, each taking O(n).
- Total Time Complexity: O(n^2).
  Explanation: Two nested loops make this solution quadratic.
Space Complexity: O(1), no extra space is used except variables.

*/
/*
// Approach: Dynamic Programming
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> maxLeft(n), maxRight(n);

        // Precompute the maximum heights to the left of each bar
        maxLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }

        // Precompute the maximum heights to the right of each bar
        maxRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }

        // Calculate the water trapped at each bar
        int totalWater = 0;
        for (int i = 0; i < n; ++i) {
            totalWater += min(maxLeft[i], maxRight[i]) - height[i];
        }

        return totalWater;
    }
};


Time Complexity:
- Precomputing maxLeft and maxRight takes O(n) each.
- Calculating the trapped water takes O(n).
- Total Time Complexity: O(n).
  Explanation: Linear time is achieved due to precomputation of left and right maximum heights.
Space Complexity: O(n), for the maxLeft and maxRight arrays.

*/
/*
// Approach: Monotonic Stack
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int totalWater = 0;

        for (int i = 0; i < height.size(); ++i) {
            // Process all bars that can trap water with the current bar
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                // If the stack becomes empty, break
                if (st.empty()) break;

                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                totalWater += distance * boundedHeight;
            }

            st.push(i);
        }

        return totalWater;
    }
};


Time Complexity:
- Each bar is pushed and popped from the stack once.
- Total Time Complexity: O(n).
  Explanation: Linear time is achieved due to efficient processing using the stack.
Space Complexity: O(n), for the stack used to store indices.

*/