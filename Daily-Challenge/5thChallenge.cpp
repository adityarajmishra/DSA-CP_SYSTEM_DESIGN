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
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
    
private:
    int helper(TreeNode* node, int minVal, int maxVal) {
        if (!node) {
            return maxVal - minVal; 
        }
        
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);
        
        int left = helper(node->left, minVal, maxVal);
        int right = helper(node->right, minVal, maxVal);
        
        return max(left, right);
    }
};