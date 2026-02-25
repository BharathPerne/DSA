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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;
        
        // Update current number by shifting left and adding current node's value
        currentSum = (currentSum << 1) | node->val;
        
        // If leaf node, return the current number
        if (!node->left && !node->right) {
            return currentSum;
        }
        
        // Otherwise, continue DFS on left and right subtrees
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};