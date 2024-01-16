class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }

        std::vector<std::string> mapping = {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        generateCombinations(digits, 0, "", mapping, result);
        return result;
    }

private:
    void generateCombinations(const std::string& digits, int index, std::string current,
                              const std::vector<std::string>& mapping, std::vector<std::string>& result) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char letter : mapping[digit - 2]) {
            generateCombinations(digits, index + 1, current + letter, mapping, result);
        }
    }
};