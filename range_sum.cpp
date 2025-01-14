#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1}; // Example input
    NumArray numArray(nums);

    // Example queries
    cout << "Sum of range [0, 2]: " << numArray.sumRange(0, 2) << endl; // Output: 1
    cout << "Sum of range [2, 5]: " << numArray.sumRange(2, 5) << endl; // Output: -1
    cout << "Sum of range [0, 5]: " << numArray.sumRange(0, 5) << endl; // Output: -3

    return 0;
}
