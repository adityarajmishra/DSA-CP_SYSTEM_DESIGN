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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        vector<int> seq2;
        
        getLeafSequence(root1, seq1);
        getLeafSequence(root2, seq2);
        
        return seq1 == seq2;
    }
    
private:
    void getLeafSequence(TreeNode* node, vector<int>& seq) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            seq.push_back(node->val); 
            return;
        }
        
        getLeafSequence(node->left, seq);
        getLeafSequence(node->right, seq);
    }
};