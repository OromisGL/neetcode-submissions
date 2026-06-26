class Solution {
public:
    bool isPalindrome(string s) {
        string pal;

        for (char& c : s){
            if (isalnum(c)) pal += c >= 'A' && c <= 'Z' ? c + 32 : c; 
        }

        int left = 0; 
        int right = pal.size() - 1;

        while (left < right) {
            if (pal[left] != pal[right]) return false;
            right--;
            left++;
        }

        return true;
    }
};
