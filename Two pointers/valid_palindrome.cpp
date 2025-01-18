#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters, ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
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
- Each character is processed at most once (skipped or compared).
- Total Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as the checks are performed in-place without extra memory.
*/

int main() {
    string s = "A man, a plan, a canal: Panama"; // Example input

    Solution solution;
    bool result = solution.isPalindrome(s);

    cout << "Is the string a valid palindrome? " << (result ? "Yes" : "No") << endl;

    return 0;
}
/*
// Approach: Reverse and Compare
class Solution {
public:
    bool isPalindrome(string s) {
        string filtered, reversed;

        // Filter non-alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) filtered += tolower(c);
        }

        // Create the reversed version of the filtered string
        reversed = filtered;
        reverse(reversed.begin(), reversed.end());

        // Check if the original filtered string matches its reverse
        return filtered == reversed;
    }
};


Time Complexity:
- Filtering step takes O(n).
- Reversing the string takes O(n).
- Comparison takes O(n).
- Total Time Complexity: O(n).
Space Complexity: O(n), as two additional strings are created.

*/
