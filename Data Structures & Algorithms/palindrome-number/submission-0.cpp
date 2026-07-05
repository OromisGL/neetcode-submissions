class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        if (x < 0) return false;

        while (x > 0) {
            int d = x % 10;
            arr.push_back(d);
            x /= 10;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != arr[arr.size() - i - 1]) return false;
        }

        return true;
    }
};