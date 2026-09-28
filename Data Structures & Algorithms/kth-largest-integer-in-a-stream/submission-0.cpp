class KthLargest {
public:
    priority_queue<int> pq;
    int key = 0;
    int val = 0; 

    KthLargest(int k, vector<int>& nums) {
        for (int i : nums) pq.push(i);
        key = k;
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> q = pq;
        int i = 0;
        while (i < key - 1) {q.pop(); i++;}
        return q.top();
    }
};
