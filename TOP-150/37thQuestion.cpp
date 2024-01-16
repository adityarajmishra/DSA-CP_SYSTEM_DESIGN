class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Find the first decreasing element from the right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // If such element is found, find the smallest element to the right of it that is greater
        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        // Reverse the elements to the right of the first decreasing element
        reverse(nums.begin() + i + 1, nums.end());
    }
};