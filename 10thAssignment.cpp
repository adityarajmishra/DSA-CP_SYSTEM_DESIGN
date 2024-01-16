class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, -1)); // Initialize result matrix with -1
        
        queue<pair<int, int>> q;
        
        // Initialize queue with the positions of 0s and mark them as distance 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Possible directions to move: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            
            for (const auto& dir : directions) {
                int newRow = current.first + dir.first;
                int newCol = current.second + dir.second;
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && result[newRow][newCol] == -1) {
                    result[newRow][newCol] = result[current.first][current.second] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        
        return result;
    }
};