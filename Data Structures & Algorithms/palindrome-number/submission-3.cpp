class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int dx = x;
        int y = 0;

        while (x > 0) {
            int d = x % 10;
            y = y * 10 + d;
            x /= 10;
        }

        return y == dx;
    }
};