class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the total sum is odd, it's impossible to partition into two subsets with equal sums
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int targetSum = totalSum / 2;
        int n = nums.size();
        
        // dp[i][j] is true if there exists a subset of nums[0..i-1] with a sum equal to j
        vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));
        
        // Initialization
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        
        // Fill the dp array
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= targetSum; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
        return dp[n][targetSum];
    }
};