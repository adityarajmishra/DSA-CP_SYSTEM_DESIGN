class Solution {
public:
    bool isPalindrome(string s) {
        // Remove non-alphanumeric characters and convert to lowercase
        string cleanedString;
        for (char c : s) {
            if (isalnum(c)) {
                cleanedString += tolower(c);
            }
        }

        // Check if the cleaned string is a palindrome
        int left = 0;
        int right = cleanedString.size() - 1;

        while (left < right) {
            if (cleanedString[left] != cleanedString[right]) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }
};