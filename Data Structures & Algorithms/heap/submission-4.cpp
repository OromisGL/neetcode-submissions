class MinHeap {
public:

    vector<int> heap;

    MinHeap() {}

    void push(int val) {
        if (heap.size() == 0) {
            heap.push_back(val);
            return;
        }
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    int pop() {
        if (heap.size() == 0) return -1;
        int ret = heap[0];
        swap(heap[0], heap[heap.size() - 1]);

        heap.pop_back();
        heapify(heap);
        return ret;
    }

    int top() {
        if (heap.size() == 0) return -1;
        return heap[0];
    }

    void siftUp(int i ) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] < heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void siftDown(int i) {
        int low = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;    

        if (left < heap.size() && heap[low] > heap[left]) low = left;
        if (right < heap.size() && heap[low] > heap[right]) low = right;

        if (low != i) {
            swap(heap[i], heap[low]);
            siftDown(low);
        }
    }

    void heapify(const vector<int>& arr) {
        heap = arr;

        for (int i = (heap.size() / 2) - 1; i >= 0; i--){
            siftDown(i);
        }

    }
};
