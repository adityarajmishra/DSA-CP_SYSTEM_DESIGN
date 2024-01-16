class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        istringstream ss(s);
        string word;
        int i = 0;
        
        while (getline(ss, word, ' ')) {
            if (i == pattern.length() || charToWord.count(pattern[i]) && charToWord[pattern[i]] != word ||
                wordToChar.count(word) && wordToChar[word] != pattern[i]) {
                return false;
            }
            
            charToWord[pattern[i]] = word;
            wordToChar[word] = pattern[i];
            i++;
        }
        
        return i == pattern.length();
    }
};