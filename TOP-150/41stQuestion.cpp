class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToTMapping;
        unordered_map<char, char> tToSMapping;

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char sChar = s[i];
            char tChar = t[i];

            // Check s to t mapping
            if (sToTMapping.find(sChar) == sToTMapping.end()) {
                sToTMapping[sChar] = tChar;
            } else {
                if (sToTMapping[sChar] != tChar) {
                    return false;
                }
            }

            // Check t to s mapping
            if (tToSMapping.find(tChar) == tToSMapping.end()) {
                tToSMapping[tChar] = sChar;
            } else {
                if (tToSMapping[tChar] != sChar) {
                    return false;
                }
            }
        }

        return true;
    }
};
