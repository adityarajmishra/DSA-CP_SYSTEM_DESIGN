class Solution {
public:

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.length() < p.length()) {
        return result; 
    }

    unordered_map<char, int> pFreq;
    for (char c : p) {
        pFreq[c]++;
    }

    unordered_map<char, int> windowFreq;
    for (int i = 0; i < s.length(); i++) {
        windowFreq[s[i]]++;
        
        if (i >= p.length()) {
            if (windowFreq[s[i - p.length()]] == 1) {
                windowFreq.erase(s[i - p.length()]);
            }
            else {
                windowFreq[s[i - p.length()]]--; 
            }
        }

        if (pFreq == windowFreq) {
            result.push_back(i - p.length() + 1);
        }
    }
    return result;
}
};