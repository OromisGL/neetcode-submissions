class DynamicArray {
public:

    int m_cap = 0;
    int m_size = 0;
    int* m_array;

    DynamicArray(int capacity) {
        m_array = new int[capacity];
        m_cap = capacity;
    }

    ~DynamicArray() {
        delete [] m_array;
    }

    int get(int i) {
        if (i >= m_cap) return 0;
        return m_array[i];
    }

    void set(int i, int n) {   
        if (i >= m_cap) return;
        m_array[i] = n;
    }

    void pushback(int n) {
        if (m_size == m_cap)
            resize();
        m_size++;
        m_array[m_size - 1] = n;
    }

    int popback() {
        int ret = m_array[m_size - 1];
        m_size--;
        return ret;
    }

    void resize() {
        int new_cap = m_cap * 2;
        int* temp = new int[new_cap];

        for (int i = 0; i < m_size; i++){
            temp[i] = m_array[i];
        }

        delete [] m_array;
        m_array = temp;
        m_cap = new_cap;
        
    }

    int getSize() {
        return m_size;
    }

    int getCapacity() {
        return m_cap;
    }
};
