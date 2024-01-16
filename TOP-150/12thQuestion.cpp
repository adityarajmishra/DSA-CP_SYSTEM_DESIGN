class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;

        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                // If the current index is beyond the maximum reachable index, return false
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= n - 1) {
                // If we can reach the last index, return true
                return true;
            }
        }

        return false;
    }
};