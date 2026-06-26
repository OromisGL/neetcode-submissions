class LinkedList {
public:
    struct ListNode {
        ListNode* next = nullptr;
        int val;
    };
    ListNode* head;
    ListNode* dummy;

    LinkedList() {
        dummy = new ListNode();
        head = new ListNode();
        head = dummy;
    }

    int get(int index) {
        int i = 0;
        ListNode* curr = dummy->next;
        while (curr){
            if (i == index) {
                return curr->val;
            } else {
                curr = curr->next;
                i++;
            }
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* n = new ListNode();
        n->val = val;
        if (head->next == dummy || dummy->next == nullptr) {
            head = n;
        }
        
        n->next = dummy->next;
        dummy->next = n;
    }
    
    void insertTail(int val) {
        ListNode* n = new ListNode();
        n->val = val;
        head->next = n;
        head = n;
    }

    bool remove(int index) {
        ListNode* prev = dummy;
        for (int i = 0; i < index; i++){
            prev = prev->next;
            if (prev == nullptr) return false;
        }

        if (prev->next == nullptr ) return false;
        if (prev->next == head) head = prev;

        ListNode* del = prev->next;

        prev->next = prev->next->next;

        delete del;
        return true;
    }

    vector<int> getValues() {
        vector <int> ret;
        ListNode* curr = dummy->next;
        while (curr) {
            ret.push_back(curr->val);
            curr = curr->next;
        }

        return ret;
    }
};
