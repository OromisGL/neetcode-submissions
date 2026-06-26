class Deque {
public:

    struct Q{
        Q* prev = nullptr;
        Q* next = nullptr;
        int val;
    };

    Q* tail;
    Q* head;

    Deque() {
        tail = new Q();
        head = new Q();

        tail->prev = head;
        head->next = tail;
    }

    bool isEmpty() {
        return tail->prev == head && head->next == tail;
    }

    void append(int value) {
        Q* n = new Q();
        n->val = value;
        n->prev = tail->prev;
        n->next = tail;

        tail->prev->next = n;
        tail->prev = n;
    }

    void appendleft(int value) {
        Q* n = new Q();
        n->val = value;
        n->prev = head;
        n->next = head->next;

        head->next->prev = n;
        head->next = n;
    }

    int pop() {
        if (isEmpty()) return -1;
        Q* rm = tail->prev;

        int ret = rm->val;

        rm->prev->next = tail;
        tail->prev = rm->prev;

        delete rm;
        return ret;
    }

    int popleft() {
        if (isEmpty()) return -1;
        Q* rm = head->next;

        int ret = rm->val;

        rm->next->prev = head;
        head->next = rm->next;

        delete rm;
        return ret;
    }
};
