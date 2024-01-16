class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                return {left + 1, right + 1};  // Indices are 1-indexed
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        // No solution found (this should not happen in the given constraints)
        return {};
    }
};