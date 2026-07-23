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

    bool check(TreeNode* left, TreeNode* right) {
        if (!left && !right ) return true;
        if (!left || !right ) return false;

        bool v = left->val == right->val;
        bool l = check(left->left, right->left);
        bool r = check(left->right, right->right);

        return l && r && v;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};
