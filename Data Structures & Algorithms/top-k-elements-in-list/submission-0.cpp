class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1 && n == 1) return {nums[0]};

        unordered_map<int,vector<int>> rank;

        for (int i = 0; i < n; i++){
            rank[nums[i]].push_back(nums[i]);
        }
        vector<pair<int, vector<int>>> ranks;

        for (const auto& [nu,vec] : rank){
            ranks.push_back({vec.size(), vec});
        }

        vector<int> ret;

        sort(ranks.begin(),ranks.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        k = min(k, (int)ranks.size());

        for (int i = 0; i < k; i++){
            ret.push_back(ranks[i].second.at(0));
        }
        return ret;
    }
};
