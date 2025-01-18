#include <iostream>
#include <vector>
using namespace std;

// Approach: Two Pointers (Optimal Solution)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1}; // Return 1-indexed positions
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {}; // This line is not needed as the problem guarantees exactly one solution
    }
};

/*
Time Complexity:
- The algorithm uses a single pass through the array with two pointers.
- Total Time Complexity: O(n).
  Explanation: The two pointers traverse the array once, making it a linear time solution.
Space Complexity: O(1), as no extra space is used except for the result vector.
*/

int main() {
    vector<int> numbers = {2, 7, 11, 15}; // Example input
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(numbers, target);

    cout << "Indices of the two numbers that add up to " << target << ": ";
    cout << result[0] << " " << result[1] << endl; // Output: 1 2

    return 0;
}
/*
// Approach: Brute Force (Checking All Pairs)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        // Iterate over all pairs using two nested loops
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1}; // Return 1-based indices
                }
            }
        }

        return {}; // Return empty if no pair is found
    }
};


Time Complexity:
- The algorithm iterates through all pairs in the array using two nested loops.
- Total Time Complexity: O(n^2).
  Explanation: We check all pairs in the array.
Space Complexity: O(1), no extra space is used except the result vector.
*/
/*
// Approach: Binary Search (After Fixing One Element)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int complement = target - numbers[i];
            int left = i + 1, right = numbers.size() - 1;

            // Use binary search to find the complement
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == complement) {
                    return {i + 1, mid + 1}; // Return 1-based indices
                }
                else if (numbers[mid] < complement) {
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
- For each element, binary search takes O(log n) to find the complement.
- Total Time Complexity: O(n \log n).
  Explanation: Binary search is used for each element, which makes the time complexity O(n \log n).
Space Complexity: O(1), as no extra space is used except for the result vector.

*/