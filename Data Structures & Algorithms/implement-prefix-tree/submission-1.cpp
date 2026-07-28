class PrefixTree {
public:

    struct TreeNode {
        TreeNode* children[26];
        bool isleave = false;

        TreeNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TreeNode* root = nullptr;

    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(TreeNode* root, const string& word) {
        TreeNode* curr = root;

        for (const char c : word) {
            int index = c - 'a';

            if (!curr->children[index]) {
                TreeNode* tmp = new TreeNode();
                curr->children[index] = tmp;
            }

            curr = curr->children[index];
        }

        curr->isleave = true;
    }

    void insert(string word) {
        insert(root, word);
    }

    bool search(TreeNode* root, const string& word ) {
        if (!root) return false;

        TreeNode* curr = root;

        for (const char c : word) {
            if (!curr->children[c - 'a']) {
                return false;
            }

            curr = curr->children[c - 'a'];
        }

        return curr->isleave;
    }

    bool prefixsearch(TreeNode* root, const string& word) {
        if (!root) return false;

        TreeNode* curr = root;

        for (const char c : word) {
            if (!curr->children[c - 'a']) {
                return false;
            }

            curr = curr->children[c - 'a'];
        }

        return true;
    }
    
    bool search(string word) {
        return search(root, word);
    }
    
    bool startsWith(string prefix) {
        return prefixsearch(root, prefix);
    }
};
