#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // Pointer for the last element of initialized nums1
        int j = n - 1;  // Pointer for the last element of nums2
        int k = m + n - 1;  // Pointer for the last position in nums1

        // Merge the arrays from the end to the beginning
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // If there are remaining elements in nums2, copy them
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

/*
Time Complexity:
- We traverse both arrays once, comparing and placing elements in the correct position.
- Total Time Complexity: O(m + n).
  Explanation: We traverse both arrays once from the end to the beginning.
Space Complexity: O(1), as we are performing the merge in-place without using extra space.
*/

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};  // Example input
    vector<int> nums2 = {2, 5, 6};
    int m = 3;  // Number of initialized elements in nums1
    int n = 3;  // Number of elements in nums2

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    // Output the merged array
    cout << "Merged array: ";
    for (int i = 0; i < m + n; ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
