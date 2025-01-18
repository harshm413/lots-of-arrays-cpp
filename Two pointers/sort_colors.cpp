#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap nums[low] and nums[mid], increment low and mid
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Move the mid pointer when the value is 1
                mid++;
            } else {
                // Swap nums[mid] and nums[high], decrement high
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
Time Complexity:
- The algorithm uses a single pass over the array with three pointers, making it O(n), where n is the number of elements in the array.
Space Complexity: O(1), as it uses a constant amount of extra space for the pointers.
*/

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};  // Example input

    Solution solution;
    solution.sortColors(nums);

    // Output the sorted array
    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
