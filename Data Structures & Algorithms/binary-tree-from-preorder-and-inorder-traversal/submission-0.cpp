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

    TreeNode* addNode(int preord, int inord, int end, vector<int>& preorder, unordered_map<int, int>& pos) {
        if (inord > end) return nullptr;
        int val = preorder[preord];
        TreeNode* node = new TreeNode(val);
        int pivot = pos[val];
        int left_s = pivot - inord;

        node->left = addNode(preord + 1, inord, pivot - 1, preorder, pos);
        node->right = addNode(preord + 1 + left_s, pivot + 1, end, preorder, pos);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        if (n == 1) return new TreeNode(preorder[0]);

        unordered_map<int, int> pos;
        for (int i = 0; i< n; i++) {
            pos[inorder[i]] = i;
        }

        return addNode(0, 0, n - 1, preorder, pos);

    }
};










