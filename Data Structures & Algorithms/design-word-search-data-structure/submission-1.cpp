class WordDictionary {
public:

    struct TreeNode {
        TreeNode* children[26] = {};
        bool isLeave = false;
    };

    TreeNode* root = nullptr;

    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* curr = root;

        for (const char c : word) {
            int index = c - 'a';

            if (!curr->children[index]){
                TreeNode* tmp = new TreeNode();

                curr->children[index] = tmp;   
            }
            curr = curr->children[index];
        }

        curr->isLeave = true;
    }

    bool searchNode(TreeNode* node, int i,  string& w) {

        if (i == w.size()) return node->isLeave;

        if (w[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] && searchNode(node->children[j], i + 1, w)) {
                    return true;
                }
            }
        } else {
            int idx = w[i] - 'a';
            return node->children[idx] && searchNode(node->children[idx], i + 1, w);
        }
        return false;
    }

    bool search(string word) {
        if (!root) return false;

        return searchNode(root, 0, word);
    }
};
