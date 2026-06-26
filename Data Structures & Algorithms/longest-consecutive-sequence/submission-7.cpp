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
        int ar = find(a);
        int br = find(b);
        if (ar == br) return;

        if (size[ar] < size[br]) swap(ar,br);
        parent[br] = ar;
        size[ar] += size[br];
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int best = 0;
        for (int x : nums){
            parent[x] = x;
            size[x] = 1;
        }

        for (int x : nums){
            if (parent.contains(x + 1)){
                unite(x, x+1);
            }
        }

        for (const auto& [val, siz] : size){
            best = max(best, siz);
        }

        return best;
    }
};


















