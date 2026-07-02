class MinHeap {
public:
    
    vector<int> heap;

    int head = 0;
    int val = 0;

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
        int ret = heap[head];
        swap(heap[head], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(heap);
        return ret;
    }

    int top() {
        if (heap.size() == 0) return -1;
        return heap[head];
    }

    void siftDown(int i ){
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            siftDown(smallest);
        }
    }

    void siftUp(int i) {
        while (i > 0) {
            int par = (i - 1) / 2;

            if (heap[i] < heap[par]) {
                swap(heap[i], heap[par]);
                i = par;
            } else {
                break;
            }
        }
    }

    void heapify(const vector<int>& arr) {
        heap = arr;

        for (int i = (heap.size() / 2) - 1; i >= 0; i--){
            siftDown(i);
        }
    }
};
