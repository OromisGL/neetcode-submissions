class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); 

        int total = 0;
        int totalval = 0; 
        int res = 0;
        for (int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            totalval += diff;
            if (total < 0) {
                res = i + 1;
                total = 0;
            }
        }
        
        if (totalval < 0) return -1;

        return res;

    }
};
