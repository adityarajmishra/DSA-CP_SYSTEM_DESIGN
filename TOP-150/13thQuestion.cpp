class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, currentEnd = 0, farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {
                // We've reached the current maximum reachable index, update for the next jump
                currentEnd = farthest;
                ++jumps;

                if (currentEnd >= n - 1) {
                    // If the last index can be reached, break early
                    break;
                }
            }
        }

        return jumps;
    }
};