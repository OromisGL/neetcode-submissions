class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        vector<vector<int>> bucket(n + 1);
        vector<int> ret;
        for (int i : nums) freq[i]++;

        for (const auto& [v,f] : freq){
            bucket[f].push_back(v);
        }

        for (int i = n; i >= 0 && ret.size() < k; i--){
            for (int j : bucket[i]){
                ret.push_back(j);
                if (ret.size() == k) break;
            }
        }  
        return ret;

    }
};
