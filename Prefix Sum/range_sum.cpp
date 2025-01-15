#include <iostream>
#include <vector>
using namespace std;

/*
// Approach: Brute Force
class NumArray {
private:
    vector<int> nums;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums; // Store the input array
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; ++i) {
            sum += nums[i]; // Add elements in the range [left, right]
        }
        return sum;
    }
};

Time Complexity:
- Query Time: O(n), where n is the number of elements in the range [left, right].
  Explanation: Each query iterates through the range [left, right], performing O(n) additions.
- Preprocessing Time: O(1), as no preprocessing is required.
- Total for q queries: O(q * n), where q is the number of queries.
*/

// Approach: Prefix Sum Array
class NumArray {
private:
    vector<int> prefixSums;

public:
    // Constructor to initialize the prefix sums
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSums.resize(n + 1, 0); // Initialize with size n+1 to store prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
    }

    // Function to calculate the sum of elements in the range [left, right]
    int sumRange(int left, int right) {
        return prefixSums[right + 1] - prefixSums[left];
    }
};

/*
Time Complexity:
- Query Time: O(1), as each query requires just two prefix sums and a subtraction.
  Explanation: The range sum is calculated in constant time using precomputed prefix sums.
- Preprocessing Time: O(n), where n is the size of the input array.
  Explanation: A single pass through the array is used to compute prefix sums.
- Total for q queries: O(n + q), where q is the number of queries.
*/

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1}; // Example input
    NumArray numArray(nums);

    // Example queries
    cout << "Sum of range [0, 2]: " << numArray.sumRange(0, 2) << endl; // Output: 1
    cout << "Sum of range [2, 5]: " << numArray.sumRange(2, 5) << endl; // Output: -1
    cout << "Sum of range [0, 5]: " << numArray.sumRange(0, 5) << endl; // Output: -3

    return 0;
}
