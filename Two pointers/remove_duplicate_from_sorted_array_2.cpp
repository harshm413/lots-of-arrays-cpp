#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int newLength = 2; // Tracks the position for valid elements

        for (int i = 2; i < nums.size(); ++i) {
            // Check if the current element is not equal to nums[newLength - 2]
            if (nums[i] != nums[newLength - 2]) {
                nums[newLength] = nums[i]; // Move valid element to the next position
                newLength++;
            }
        }

        return newLength;
    }
};

/*
Time Complexity:
- The array is traversed once with two pointers.
- Total Time Complexity: O(n).
  Explanation: Linear traversal ensures each element is processed at most once.
Space Complexity: O(1), as the operation is performed in-place without extra memory.
*/

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; // Example input

    Solution solution;
    int newLength = solution.removeDuplicates(nums);

    cout << "New length of the array after removing duplicates: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
