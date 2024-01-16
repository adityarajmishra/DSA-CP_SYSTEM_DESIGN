class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentSubset;

        backtrack(nums, 0, currentSubset, result);

        return result;
    }

private:
    void backtrack(const std::vector<int>& nums, int start, std::vector<int>& currentSubset, std::vector<std::vector<int>>& result) {
        result.push_back(currentSubset);

        for (int i = start; i < nums.size(); ++i) {
            currentSubset.push_back(nums[i]);
            backtrack(nums, i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
};