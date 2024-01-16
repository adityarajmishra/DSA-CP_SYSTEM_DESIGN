class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCount;

        // Count characters in magazine
        for (char ch : magazine) {
            charCount[ch]++;
        }

        // Check if ransomNote can be constructed
        for (char ch : ransomNote) {
            if (charCount.find(ch) == charCount.end() || charCount[ch] == 0) {
                return false;
            }
            charCount[ch]--;
        }

        return true;
    }
};
