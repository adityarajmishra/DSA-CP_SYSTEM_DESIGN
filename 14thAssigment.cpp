class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        int m = board.size();
        int n = board[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
            return false;
        }

        if (k == word.size() - 1) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '*'; // Mark the cell as visited

        // Explore adjacent cells
        if (dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i + 1, j, k + 1) ||
            dfs(board, word, i, j - 1, k + 1) || dfs(board, word, i, j + 1, k + 1)) {
            return true;
        }

        board[i][j] = temp; // Backtrack by restoring the original value
        return false;
    }
};