class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInter) {
        int n = inter.size();
        if (n == 0) return {newInter};

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
           while (i < n && inter[i][1] < newInter[0]) {
                res.push_back(inter[i++]);
           } 
           while (i < n && inter[i][0] <= newInter[1]) {
                newInter[0] = min(newInter[0], inter[i][0]);
                newInter[1] = max(newInter[1], inter[i][1]);
                i++;
           }
           res.push_back(newInter);
           while (i < n) {
                res.push_back(inter[i++]);
           }
        }

        return res;

    }
};
