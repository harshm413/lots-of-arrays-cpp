#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                // Try skipping either the left character or the right character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

/*
Time Complexity:
- The `isPalindrome` helper function takes O(n) for a single check.
- In the worst case, we call it twice, so O(2n) = O(n).
Space Complexity:
- O(1), as no extra space is used beyond variables.
*/

int main() {
    string s = "abca"; // Example input

    Solution solution;
    bool result = solution.validPalindrome(s);

    cout << "Can the string be a valid palindrome after deleting at most one character? " 
         << (result ? "Yes" : "No") << endl;

    return 0;
}
/*
// Approach: Brute Force by Removing Each Character
class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }

    bool validPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            string modified = s.substr(0, i) + s.substr(i + 1);
            if (isPalindrome(modified)) return true;
        }
        return false;
    }
};

Time Complexity:
- Checking if a string is a palindrome takes O(n).
- Modifying the string and checking for all characters takes O(n^2) in total.
- Total Time Complexity: O(n^2).
Space Complexity:
- O(n), due to the space required to create modified substrings.

*/