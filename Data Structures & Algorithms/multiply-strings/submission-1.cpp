class Solution {
public:
    string multiply(string num1, string num2) {
        string ret = "";
        int n = num1.size(), m = num2.size();
        vector<int> num(n + m, 0);
        for (int j = n - 1; j >= 0; j--) {
            for (int i = m - 1; i>= 0; i--) {
                int mul = (num1[j] - '0') * (num2[i] - '0');
                int sum = mul + num[i + j + 1];
                num[i + j + 1] = sum % 10;
                num[i + j] += sum / 10;
            }
        }

        for (int i : num) {
            if (!(ret.empty() && i == 0)) {
                ret += (i + '0');
            }
        }

        return ret.empty() ? "0" : ret;
    }
};
