class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret;
        unordered_map<int,int> count;
        vector<vector<int>> bucket(n + 1);

        for (int n : nums) {
            count[n]++;
        }
        for (const auto& v : count) {
            bucket[v.second].push_back(v.first);
        }
        
        for (int i = n; i >= 0 && ret.size() < k; i--){
            for (int v : bucket[i]){
                ret.push_back(v);
                if(ret.size() == k) break;
            }
        }

        return ret;
    }
};
