class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        unordered_set<int> seq;
        int maxlen = 1;
        for (int i = 0; i<n; i++){
            seq.insert(nums[i]);
        }

        for (int i = 0; i < n; i++){
            if (seq.contains(nums[i] - 1)) continue;
            int len = 0;
            for (int j = 0; j <= 1000000000; j++){
                if (seq.contains(nums[i] + j)) len++;
                else {
                    break;
                }
            }

            maxlen = max(len, maxlen);
            len = 0;
        }

        return maxlen;
    }
};
