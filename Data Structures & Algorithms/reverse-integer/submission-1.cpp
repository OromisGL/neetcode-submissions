class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        if (neg) x = abs(x);
        long long n = 0; 

        while (x) {
            n = n * 10 + x % 10;
            x /= 10;
        }
        if (n < 0 || n > INT_MAX - 1) return 0;

        return neg ? -1 * n : n;
    }
};
