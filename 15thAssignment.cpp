class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};  // Special case: only one node
        }

        vector<int> degrees(n, 0);
        vector<unordered_set<int>> adjList(n);

        for (const auto& edge : edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;

            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }

        queue<int> leaves;

        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                leaves.push(i);
            }
        }

        while (n > 2) {
            int leavesCount = leaves.size();

            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : adjList[leaf]) {
                    degrees[neighbor]--;

                    if (degrees[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }

                n--;
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};