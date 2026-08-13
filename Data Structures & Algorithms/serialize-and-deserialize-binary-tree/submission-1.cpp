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

class Codec {
public:

    void encode(TreeNode* root, string& key) {
        if (!root) {
            key += "#,";
            return;
        }

        key += to_string(root->val) + ",";
        encode(root->left, key);
        encode(root->right, key);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string key;
        encode(root, key);
        return key;
    }

    TreeNode* build(queue<int>& q) {
        int val = q.front();
        q.pop();

        if (val == INT_MIN) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(val);

        root->left = build(q);
        root->right = build(q);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        int n = data.size();

        if (n == 0) return {};

        queue<int> q;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            if (token == "#") {
                q.push(INT_MIN);
            } else {
                q.push(stoi(token));
            }
        }

        if (n == 1) return new TreeNode(q.front());

        return build(q);
    }
};








