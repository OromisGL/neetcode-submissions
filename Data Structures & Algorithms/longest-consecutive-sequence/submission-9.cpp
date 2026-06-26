class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return;

        if (size[pa] < size[pb]) swap(pa,pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        for (int x : nums) {
            parent[x] = x;
            size[x] = 1;
            }
        for (int i = 0; i < n; i++){
            if (parent.contains(nums[i] + 1)) {
                unite(nums[i], nums[i] + 1);
            }
        }
        int maxin = 0;
        for (const auto& s : size) {
            maxin = max(maxin, s.second);
        }
        return maxin;
    }
};
