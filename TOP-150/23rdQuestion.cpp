class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        std::vector<std::string> rows(numRows, "");
        int row = 0;
        bool goingDown = false;

        for (char ch : s) {
            rows[row] += ch;

            if (row == 0 || row == numRows - 1) {
                goingDown = !goingDown;
            }

            row += goingDown ? 1 : -1;
        }

        std::string result;
        for (const std::string& rowStr : rows) {
            result += rowStr;
        }

        return result;
    }
};