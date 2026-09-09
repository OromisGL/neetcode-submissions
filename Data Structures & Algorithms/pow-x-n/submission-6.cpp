class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1.0/x;
            n = -n;
        }

        if (n == 0){
            return 1.0;
        } 
        else if (n % 2 == 0) {
            return myPow(x * x, n / 2);
        } 
        return x * myPow(x * x, (n - 1) / 2);
    }
};
