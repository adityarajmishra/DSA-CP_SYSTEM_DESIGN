class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else {
                count += (candidate == num) ? 1 : -1;
            }
        }

        return candidate;
    }
};