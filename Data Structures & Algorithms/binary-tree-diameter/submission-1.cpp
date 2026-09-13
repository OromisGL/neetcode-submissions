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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* lastvis = nullptr;
        unordered_map<TreeNode*, int> depth;
        while (node || !st.empty()) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                TreeNode* peek = st.top();
                if(peek->right && lastvis != peek->right) {
                    node = peek->right;
                } else {
                    st.pop();
                    int l = depth[peek->left], r = depth[peek->right];
                    maxDiameter = max(maxDiameter, l + r);
                    depth[peek] = 1 + max(l, r);
                    lastvis = peek;
                }
            }
        }

        return maxDiameter;
    }
};
