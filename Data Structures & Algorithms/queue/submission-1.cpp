class Deque {
public:
    
    struct Q{
        Q* prev = nullptr;
        Q* next = nullptr;
        int val;
    };

    Q* m_head;
    Q* m_tail;

    Deque() {
        m_head = new Q();
        m_tail = new Q();
        m_head->next = m_tail;
        m_tail->prev = m_head;
    }

    bool isEmpty() {
        return m_head->next == m_tail && m_tail->prev == m_head;
    }

    void append(int value) {
        Q* n = new Q();
        n->val = value;
        n->next = m_tail;
        n->prev = m_tail->prev;

        m_tail->prev->next = n;
        m_tail->prev = n;
    }

    void appendleft(int value) {
        Q* n = new Q();
        n->val = value;
        n->next = m_head->next;
        n->prev = m_head;

        m_head->next->prev = n;
        m_head->next = n;
    }

    int pop() {
        if (isEmpty()) return -1;
        
        Q* nrm = m_tail->prev;

        int ret = nrm->val;
        nrm->prev->next = m_tail;

        m_tail->prev = nrm->prev;

        delete nrm;
        return ret;
    }

    int popleft() {
        if (isEmpty()) return -1;
        Q* nrm = m_head->next;

        int ret = nrm->val;
        nrm->next->prev = m_head;
        m_head->next = nrm->next;

        delete nrm;
        return ret;
    }
};
