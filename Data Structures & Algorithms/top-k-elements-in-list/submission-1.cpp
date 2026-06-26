class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int i : nums){
            freq[i]++;
        }
        
        int n = nums.size();

        vector<vector<int>> bucket(n + 1);
        for (const auto& [val, cnt] : freq){
            bucket[cnt].push_back(val);
        }

        vector<int> ret;
        for (int i = n; i >= 0 && ret.size() < k; i--){
            for (int j : bucket[i]){
                ret.push_back(j);
                if (ret.size() == k) break;
            }
        }

        return ret;
    }
};
