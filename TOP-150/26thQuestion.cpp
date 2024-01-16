class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;  // Index for string s
        int tIndex = 0;  // Index for string t

        while (sIndex < s.length() && tIndex < t.length()) {
            if (s[sIndex] == t[tIndex]) {
                // Match found, move to the next character in s
                sIndex++;
            }
            // Move to the next character in t
            tIndex++;
        }

        // If sIndex reached the end of s, then s is a subsequence of t
        return sIndex == s.length();
    }
};