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

    void unite(int a, int b) {
        int ax = find(a);
        int bx = find(b);

        if (ax == bx) return;

        if (size[ax] < size[bx]) swap(ax,bx);
        parent[bx] = ax;
        size[ax] += size[bx];
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
        int best = 0;

        for (auto v : size) {
            best = max(best, v.second);
        }

        return best;
    }
};
