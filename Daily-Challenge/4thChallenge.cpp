#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        findParents(root, nullptr, parent);

        TreeNode* startNode = getStartNode(root, start);
        if (!startNode) return -1;  // Return -1 if startNode is not found

        q.push(startNode);
        visited.insert(startNode);

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && visited.find(front->left) == visited.end()) {
                    q.push(front->left);
                    visited.insert(front->left);
                }
                if (front->right && visited.find(front->right) == visited.end()) {
                    q.push(front->right);
                    visited.insert(front->right);
                }
                if (parent[front] && visited.find(parent[front]) == visited.end()) {
                    q.push(parent[front]);
                    visited.insert(parent[front]);
                }
            }
            minutes++;
        }

        return minutes - 1;  // Adjust to return the correct value
    }

private:
    void findParents(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& p) {
        if (!node) return;

        p[node] = parent;
        findParents(node->left, node, p);
        findParents(node->right, node, p);
    }

    TreeNode* getStartNode(TreeNode* node, int start) {
        if (!node) return nullptr;
        if (node->val == start) return node;

        TreeNode* left = getStartNode(node->left, start);
        if (left) return left;

        return getStartNode(node->right, start);
    }
};