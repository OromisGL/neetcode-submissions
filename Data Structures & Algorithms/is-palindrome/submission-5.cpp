class Solution {
public:
    bool isPalindrome(string s) {
        string test;

        for (const char& c : s) {
            if (isalnum(c)) test += c >= 'A' && c<= 'Z' ? c + 32 : c;
        }

        int left = 0; 
        int right = test.size() - 1;

        while (left < right) {
            if (test[left] != test[right]) return false;
            right--;
            left++;
        }

        return true;
    }
};
