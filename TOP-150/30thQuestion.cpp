class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;

        if (s.empty() || words.empty()) {
            return result;
        }

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.length() < totalLen) {
            return result;
        }

        std::unordered_map<std::string, int> wordFreq;

        for (const std::string& word : words) {
            wordFreq[word]++;
        }

        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            int count = 0;
            std::unordered_map<std::string, int> seen;

            while (right + wordLen <= s.length()) {
                std::string currentWord = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.find(currentWord) != wordFreq.end()) {
                    seen[currentWord]++;
                    count++;

                    while (seen[currentWord] > wordFreq[currentWord]) {
                        std::string leftWord = s.substr(left, wordLen);
                        left += wordLen;
                        seen[leftWord]--;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};