class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        for (int d : digits) {
            num = num * 10 + d;
        }
        num++;

        vector<int> ret;
        while (num > 0) {
            ret.push_back(num % 10);
            num /= 10;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
