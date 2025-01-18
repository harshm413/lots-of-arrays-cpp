#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());  // Store unique elements of nums1
        unordered_set<int> resultSet;

        for (int num : nums2) {
            // If num is in set1, add it to the result set
            if (set1.count(num)) {
                resultSet.insert(num);
            }
        }

        // Convert result set to a vector and return
        vector<int> result(resultSet.begin(), resultSet.end());
        return result;
    }
};

/*
Time Complexity:
- Inserting elements into the hash set takes O(m), where m is the size of nums1.
- Checking each element of nums2 in the hash set takes O(1) for each lookup, resulting in O(n) for all elements in nums2.
- Total Time Complexity: O(m + n), where m is the size of nums1 and n is the size of nums2.
  Explanation: We iterate through both arrays once, using constant time set lookups.
Space Complexity: O(min(m, n)), for the hash set storing elements of nums1.
*/

int main() {
    vector<int> nums1 = {1, 2, 2, 1};  // Example input
    vector<int> nums2 = {2, 2};

    Solution solution;
    vector<int> result = solution.intersection(nums1, nums2);

    cout << "Intersection of the two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
