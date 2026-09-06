class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        vector<vector<int>> res;
        int count = 0;
        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] <= interval[0]) {
                res.push_back(interval);
            } else {
                count++;
            }
        }

        return count;
    }
};
