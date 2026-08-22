class Solution {
public:

    void backtrack(int i, unordered_set<int>& seen, vector<int>& c, vector<vector<int>>& r, vector<int>& n) {
        if (i == n.size()) {
            r.push_back(c);
            return;
        }
        for (int d : n) {
            if (seen.contains(d)) continue;
            c.push_back(d);
            seen.insert(d);
            backtrack(i + 1, seen, c, r, n);
            c.pop_back();
            seen.erase(d);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> r;
        vector<int> c;
        unordered_set<int> seen;

        backtrack(0, seen, c, r, nums);

        return r;
    }
};
