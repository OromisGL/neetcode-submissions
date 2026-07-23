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

    bool validate(TreeNode* root, int min, int max) {
        if (!root) return true;

        if (root->val <= min || root->val >= max) return false;

        bool l = validate(root->left, min, root->val);
        bool r = validate(root->right, root->val, max);

        return l && r;
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root) return false;
        if (!root->left && !root->right) return true;
        return validate(root, INT_MIN, INT_MAX);
    }
};
