class Solution {
public:

    int sum(int x) {
        int ret = 0;
        while (x > 0) {
            int d = x % 10;
            ret += d * d;
            x /= 10; 
        }
        return ret;
    }
    unordered_set<int> seen;

    bool isHappy(int n) {
        if (n == 1)return true;
        if (seen.contains(n)) return false;
        seen.insert(n);
        return isHappy(sum(n));
    }
};
