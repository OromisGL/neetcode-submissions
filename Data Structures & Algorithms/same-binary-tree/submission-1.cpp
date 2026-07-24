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

    bool valid(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        bool v = p->val == q->val;
        bool l = valid(p->left, q->left);
        bool r = valid(p->right, q->right);

        return v && r && l;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return valid(p,q);
    }
};
