class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // dp[i] will be true if the first i characters of s can be segmented into words in the wordDict
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;  // Empty string can be segmented

        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};