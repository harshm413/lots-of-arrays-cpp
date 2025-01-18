#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int newLength = 1; // Tracks the position for unique elements

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[newLength - 1]) { // Compare with the last unique element
                nums[newLength] = nums[i]; // Move unique element to the next position
                newLength++;
            }
        }

        return newLength;
    }
};

/*
Time Complexity:
- Single traversal of the array using two pointers.
- Total Time Complexity: O(n).
  Explanation: Each element is processed at most once.
Space Complexity: O(1), as the operation is performed in-place without extra space.
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
