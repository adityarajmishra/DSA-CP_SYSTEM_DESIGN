class Solution {
public:
    std::string reverseWords(std::string s) {
        std::istringstream iss(s);
        std::string word, result;

        while (iss >> word) {
            result = word + " " + result;
        }

        // Remove the trailing space
        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};