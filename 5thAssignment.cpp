class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        int start = 0, end = 0; 
        int counter = t.size(); 
        int minStart = 0, minLen = INT_MAX;
        
        for(char &c : t) map[c]++;
        
        while(end < s.size()){
            
            if(map[s[end++]]-- > 0) 
                counter--; 
            
            while(counter == 0){  
                if(end-start < minLen){
                    minStart = start;
                    minLen = end - start; 
                }
                
                if(map[s[start++]]++ == 0) counter++;
            }  
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};