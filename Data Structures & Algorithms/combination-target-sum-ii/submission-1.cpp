class Solution {
public:

    void backtrack(int s, int t, vector<int>& c, vector<vector<int>>& r, vector<int>& n) {
        if (t == 0) {
            r.push_back(c);
            return;
        }

        for (int i = s; i < n.size(); i++) {
            if (i > s && n[i] == n[i - 1]) continue;
            if (t < 0) break;

            c.push_back(n[i]);
            backtrack(i + 1, t - n[i], c, r, n);
            c.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;

        sort(candidates.begin(), candidates.end());

        backtrack(0, target, comb, result, candidates);

        return result;
    }
};
