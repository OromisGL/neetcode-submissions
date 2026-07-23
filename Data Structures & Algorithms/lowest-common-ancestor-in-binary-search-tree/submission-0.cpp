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

    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (
            (root->val >= p->val && root->val <= q->val) || 
            (root->val <= p->val && root->val >= q->val)) {
            return root;
        }
        TreeNode* left;
        TreeNode* right;
        if (p->val < root->val) {
            left = find(root->left, p, q);
        } else if (p->val > root->val) {
            right =find(root->right, p, q);
        } 

        return left == nullptr ? right : left;
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};
