class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return intervals;

        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else if (res.back()[1] >= interval[0]){
                res.back()[1] = max(max(res.back()[1], interval[0]), interval[1]);
            }
        }
        

        return res;
    }
};
