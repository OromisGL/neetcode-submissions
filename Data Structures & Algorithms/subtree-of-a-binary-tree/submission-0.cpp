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

    bool issub(TreeNode* root, TreeNode* sub) {
        if (!root && !sub) return true;
        if (!root || !sub) return false;

        bool v = root->val == sub->val;
        bool l = issub(root->left, sub->left);
        bool r = issub(root->right, sub->right);

        return l && r && v;
    }

    bool findsub(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;

        if (issub(root, subRoot)) return true;

        return findsub(root->left, subRoot) || findsub(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return findsub(root, subRoot);
    }
};
