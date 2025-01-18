// Approach: Two Pointers (In-place reversal)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]); // Swap characters at the left and right pointers
            ++left;
            --right;
        }
    }
};

/*
Time Complexity:
- We iterate through the string once, swapping elements.
- Total Time Complexity: O(n).
  Explanation: Each character is swapped at most once.
Space Complexity: O(1), as the operation is performed in-place with no extra space.
*/
