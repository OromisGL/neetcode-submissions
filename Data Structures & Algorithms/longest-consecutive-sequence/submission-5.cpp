class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;

    int find(int x){
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a, int b){
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;

        if (size[ra] < size[rb]) swap(ra,rb);
        parent[rb] = parent[ra];
        size[ra] += size[rb];
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        for (int x : nums){
            parent[x] = x;
            size[x] = 1;
        }

        for (int x : nums){
            if (parent.count(x + 1)){
                unite(x, x+1);
            }
        }
        int best = 0;
        for (const auto& [val,siz] : size){
            best = max(best, siz);
        }

        return best;

    }
};
