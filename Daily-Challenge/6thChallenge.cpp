class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int countA = 0, countB = 0;
        
        // Count vowels in the first half
        for (int i = 0; i < n / 2; ++i) {
            if (vowels.count(s[i]) > 0) {
                countA++;
            }
        }
        
        // Count vowels in the second half
        for (int i = n / 2; i < n; ++i) {
            if (vowels.count(s[i]) > 0) {
                countB++;
            }
        }
        
        return countA == countB;
    }
};