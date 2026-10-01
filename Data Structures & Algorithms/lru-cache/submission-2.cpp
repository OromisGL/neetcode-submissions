class LRUCache {
public:

    struct Node {
        Node* prev = nullptr;
        Node* next = nullptr;
        int val;
        int key; 
        Node(int _key, int _val) : key(_key), val(_val) {};
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int cap = 0;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!mp.contains(key)) { return -1; }
        remNode(mp[key]);
        addNode(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            mp[key]->val = value;
            remNode(mp[key]);
            addNode(mp[key]);

        } else {
            if (mp.size() == cap) {
                mp.erase(tail->prev->key);
                remNode(tail->prev);
            }
            mp[key] = new Node(key, value);
            addNode(mp[key]);
        }
    }

    void remNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;

    }
};
