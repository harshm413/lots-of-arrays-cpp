#include <iostream>
#include <vector>
using namespace std;

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
