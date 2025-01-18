#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int newLength = 0; // Tracks the position for valid elements

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[newLength] = nums[i]; // Move valid element to the front
                newLength++;
            }
        }

        return newLength;
    }
};

/*
Time Complexity:
- The algorithm iterates over the array once to process all elements.
- Total Time Complexity: O(n).
  Explanation: Each element is checked and moved at most once.
Space Complexity: O(1), as the operations are done in-place without extra memory.
*/

int main() {
    vector<int> nums = {3, 2, 2, 3}; // Example input
    int val = 3;

    Solution solution;
    int newLength = solution.removeElement(nums, val);

    cout << "New length of the array after removing " << val << ": " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
