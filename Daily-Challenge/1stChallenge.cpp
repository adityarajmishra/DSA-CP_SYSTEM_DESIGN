class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        // vector of unordered maps to store the count of arithmetic subsequences
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];

                // Add the count of subsequences ending at index j to index i
                dp[i][diff] += dp[j].count(diff) ? dp[j][diff] + 1 : 1;

                // Add the count of subsequences ending at index j to the result
                result += dp[j].count(diff) ? dp[j][diff] : 0;
            }
        }

        return result;
    }
};