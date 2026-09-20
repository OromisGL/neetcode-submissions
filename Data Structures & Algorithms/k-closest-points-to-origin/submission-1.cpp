class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int, vector<int>>>> q;

        for (auto& p : points){
            q.emplace(p[0]*p[0]+p[1]*p[1], p);
        }

        vector<vector<int>> res;

        while (k > 0 && !q.empty()) {
            res.push_back(q.top().second);
            q.pop();
            k--;
        }

        return res;
        
    }
};
