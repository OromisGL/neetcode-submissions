class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();
        string check;
        check.reserve(s.size());

        for (char ch : s) {
            unsigned char c = static_cast<unsigned char>(ch);
            if (isalnum(c)) check += static_cast<char>(tolower(c));
        }

        int m = check.size();
        int left = 0; 
        int right = m - 1;

        while (left < right) {
            if (check[left] != check[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};
