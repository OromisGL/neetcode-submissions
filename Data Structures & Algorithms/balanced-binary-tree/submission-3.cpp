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


    int getHight(TreeNode* node) {
        if (!node) return 0;
        int left = getHight(node->left);
        int right = getHight(node->right);
        
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = getHight(root->left);
        int right = getHight(root->right);

        return abs(left - right) <= 1 && isBalanced(root->left) &&isBalanced(root->right) ;
    }
};
