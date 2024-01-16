class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0;
        int minutes = 0;

        queue<pair<int, int>> rotten;

        // Count fresh oranges and enqueue rotten oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }

        while (!rotten.empty() && freshOranges > 0) {
            int size = rotten.size();

            for (int i = 0; i < size; ++i) {
                int row = rotten.front().first;
                int col = rotten.front().second;
                rotten.pop();

                // Possible directions to move: up, down, left, right
                int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                for (const auto& dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        rotten.push({newRow, newCol});
                    }
                }
            }

            minutes++;
        }

        return (freshOranges == 0) ? minutes : -1;
    }
};