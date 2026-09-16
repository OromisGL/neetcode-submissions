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
    int goodNodes(TreeNode* root) {
        int count = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            auto [curr, maxval] = q.front();
            q.pop();

            if (curr->val >= maxval) {
                count++;
            }

            int nextmax = max(maxval, curr->val);
            if (curr->right) {
                q.push({curr->right, nextmax});
            } 
            if (curr->left) {
                q.push({curr->left, nextmax});
            }
        }

        return count;
    }
};
