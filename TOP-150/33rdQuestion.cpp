class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        for (int num : nums) {
            if (num != 0) {
                nums[insertPos++] = num; 
            }
        }
        
        for (int i = insertPos; i < nums.size(); i++) {
            nums[i] = 0; 
        }
    }
};