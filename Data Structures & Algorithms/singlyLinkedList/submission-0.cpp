class LinkedList {
public:

    struct ListNode {
        ListNode* next = nullptr;
        int val;
    };

    ListNode* m_tail;
    ListNode* m_dummy;

    LinkedList() {
        m_tail = new ListNode();
        m_dummy = new ListNode();
        m_tail = m_dummy;
    }

    int get(int index) {

        ListNode* curr = m_dummy->next;
        int i = 0;
        while (curr) {
            if (i == index) {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* add = new ListNode();
        add->val = val;

        if (m_dummy->next == nullptr || m_tail == m_dummy) {
            m_tail = add;
        }

        add->next = m_dummy->next;
        m_dummy->next = add;

    }
    
    void insertTail(int val) {
        ListNode* add = new ListNode();
        add->val = val;
        m_tail->next = add;
        m_tail = add;
    }

    bool remove(int index) {
        ListNode* prev = m_dummy;

        for (int i = 0; i < index; i++){
            prev = prev->next;
            if (prev == nullptr) return false;
        }

        if (prev->next == nullptr) return false;
        if (prev->next == m_tail) m_tail = prev;
        
        ListNode* del = prev->next;
        prev->next = prev->next->next;
        delete del;

        return true;
    }

    vector<int> getValues() {
        vector<int> ret;
        ListNode* curr = m_dummy->next;

        while (curr != nullptr) {
            ret.push_back(curr->val);
            curr = curr->next;
        }

        return ret;
    }
};
