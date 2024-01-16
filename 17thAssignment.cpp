class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates

        do {
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return result;
    }
};