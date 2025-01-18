#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Move the left pointer until it points to a vowel
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }

            // Move the right pointer until it points to a vowel
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }

            // Swap the vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

int main() {
    string s = "hello";  // Example input

    Solution solution;
    string result = solution.reverseVowels(s);

    cout << "Reversed vowels string: " << result << endl;

    return 0;
}
