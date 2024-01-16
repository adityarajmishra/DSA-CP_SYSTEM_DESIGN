class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // Map to store each number and its index
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement is already in the map
            if (numMap.find(complement) != numMap.end()) {
                // Return the indices of the two numbers
                return {numMap[complement], i};
            }
            
            // Add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // It is guaranteed that there will be exactly one solution, so this line is not expected to be reached.
        return {};
    }
};