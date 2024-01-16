class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; ++i) {
            if (!isValidUnit(board[i])) {
                return false;
            }
        }

        // Check columns
        for (int j = 0; j < 9; ++j) {
            std::vector<char> column;
            for (int i = 0; i < 9; ++i) {
                column.push_back(board[i][j]);
            }
            if (!isValidUnit(column)) {
                return false;
            }
        }

        // Check sub-boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                std::vector<char> subBox;
                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        subBox.push_back(board[x][y]);
                    }
                }
                if (!isValidUnit(subBox)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isValidUnit(const std::vector<char>& unit) {
        std::unordered_set<char> seen;

        for (char digit : unit) {
            if (digit != '.' && seen.count(digit)) {
                return false;  // Duplicate found
            }
            seen.insert(digit);
        }

        return true;
    }
};