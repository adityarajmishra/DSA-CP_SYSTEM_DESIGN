class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128, -1);
        
        int left = 0;
        int right = 0;
        
        int res = 0;
        while(right < s.length()){
            char r = s[right];
            if(chars[r] != -1)
                left = max(left, chars[r] + 1);
            
            chars[r] = right; 
            res = max(res, right-left+1);
            
            right++;
        }
        return res;
    }
};