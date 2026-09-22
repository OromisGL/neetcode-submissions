class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int,int>> sortQuer;
        for (int i = 0; i < queries.size(); i++) {
            sortQuer.emplace_back(queries[i], i);
        }
        sort(sortQuer.begin(), sortQuer.end());
        sort(intervals.begin(),intervals.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> res(queries.size());
        int i = 0;

        for (auto& [p,j] : sortQuer) {
            while (i < intervals.size() && intervals[i][0] <= p) {
                int l = intervals[i][0], r = intervals[i][1];
                q.emplace(r - l + 1, r);
                i++;
            }
            while (!q.empty() && q.top().second < p) {
                q.pop();
            }

            res[j] = q.empty() ? -1 : q.top().first;
        }
        return res;
    }
};
