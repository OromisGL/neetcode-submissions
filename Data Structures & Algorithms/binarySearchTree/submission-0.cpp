class TreeMap {
   private:
    struct TreeNode {
        TreeNode(int _val, int _key) {
            val = _val;
            key = _key;
        }
        TreeNode* right = nullptr;
        TreeNode* left = nullptr;

        int key;
        int val;
    };

    TreeNode* root = nullptr;

   public:
    TreeMap() {}

    void insert(int key, int val) {
        if (!root) {
            root = new TreeNode(val, key);
            return;
        }

        TreeNode* curr = root;

        while (curr) {
            if (key < curr->key) {
                if (curr->left == nullptr) {
                    curr->left = new TreeNode(val, key);
                    return;
                }
                curr = curr->left;
            } else if (key > curr->key) {
                if (curr->right == nullptr) {
                    curr->right = new TreeNode(val, key);
                    return;
                }
                curr = curr->right;
            } else {
                curr->val = val;
                return;
            }
        }
    }

    int get(int key) {
        if (!root) return -1;

        TreeNode* curr = root;

        while (curr) {
            if (key < curr->key) {
                curr = curr->left;
            } else if (key > curr->key) {
                curr = curr->right;
            } else {
                return curr->val;
            }
        }

        return -1;
    }

    int getMin() {
        if (!root) return -1;

        TreeNode* curr = root;

        while (curr->left) {
            curr = curr->left;
        }
        return curr->val;
    }

    int getMax() {
        if (!root) return -1;

        TreeNode* curr = root;

        while (curr->right) {
            curr = curr->right;
        }
        return curr->val;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }

        return node;
    }

    TreeNode* remove(TreeNode* node, int key) {
        if (!node) return nullptr;
        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key){
            node->right = remove(node->right, key);
        } else {
            if (node->right && !node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->left && !node->right){
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }else {
                TreeNode* temp = findMin(node->right);
                node->key = temp->key;
                node->val = temp->val;
                node->right = remove(node->right, node->key);
            }
        }
        return node;
    }

    void remove(int key) { 
        if (!root) return; 

        TreeNode* curr = root;

        root = remove(curr, key);
    }

    void travers(TreeNode* node, vector<int>& vec) {
        if(!node) return;
        travers(node->left, vec);
        vec.push_back(node->key);
        travers(node->right, vec);
    }

    std::vector<int> getInorderKeys() { 
        vector<int> vec;
        travers(root, vec);
        return vec;
    }
};
