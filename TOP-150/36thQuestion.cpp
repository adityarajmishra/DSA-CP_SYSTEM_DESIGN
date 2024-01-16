
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Helper function to count live neighbors
        auto countLiveNeighbors = [&](int i, int j) {
            int count = 0;
            for (int x = max(0, i - 1); x <= min(m - 1, i + 1); ++x) {
                for (int y = max(0, j - 1); y <= min(n - 1, j + 1); ++y) {
                    count += board[x][y] & 1;
                }
            }
            count -= board[i][j] & 1; // Exclude the cell itself
            return count;
        };

        // Update the board based on the rules
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = countLiveNeighbors(i, j);

                if (board[i][j] == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                    board[i][j] = 3; // 01 to 11, representing live to live
                }
                if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2; // 00 to 10, representing dead to live
                }
            }
        }

        // Update the board to the next state
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1; // Shift to get the next state
            }
        }
    }
};