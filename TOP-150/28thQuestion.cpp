class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();

        if (n < 3) {
            return result;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                // Skip duplicate elements
                continue;
            }

            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        // Skip duplicate elements
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        // Skip duplicate elements
                        --right;
                    }
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return result;
    }
};