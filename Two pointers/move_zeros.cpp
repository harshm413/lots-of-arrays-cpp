#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;  // Pointer to track the position of non-zero elements
        
        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[nonZeroIndex] = nums[i];
                if (nonZeroIndex != i) {
                    nums[i] = 0;  // Set the current position to 0
                }
                nonZeroIndex++;
            }
        }
    }
};

/*
Time Complexity:
- We traverse the array once, and each swap operation is O(1).
- Therefore, the total time complexity is O(n), where n is the number of elements in the array.
Space Complexity: O(1), as we are not using any extra space apart from a few variables.
*/

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};  // Example input

    Solution solution;
    solution.moveZeroes(nums);

    // Output the modified array
    cout << "Array after moving zeros: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
