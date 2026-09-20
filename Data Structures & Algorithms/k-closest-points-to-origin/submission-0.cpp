class Solution {
public:

    int euclid(int x2, int y2) {
        return x2*x2 + y2*y2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int, vector<int>>>> q;

        for (auto& p : points){
            int dist = euclid(p[0],p[1]);
            q.emplace(dist, p);
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
