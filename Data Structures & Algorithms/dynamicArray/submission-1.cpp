class DynamicArray {
public:

    int cap = 0;
    int size = 0;

    int* arr;

    DynamicArray(int capacity) {
        arr = new int[capacity];
        cap = capacity;
    }

    int get(int i) {
        if (i >= size) return -1;

        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(cap == size) resize();

        size++;
        arr[size - 1] = n;
    }

    int popback() {
        int ret = arr[size - 1];
        int* temp = new int[cap];
        for (int i = 0; i < size - 1; i++) {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
        size--;
        return ret;
    }

    void resize() {
        cap *= 2;
        int* temp = new int[cap];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
