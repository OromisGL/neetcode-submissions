class Solution {
public:

    void backtrack(int n, int left, int right, string& comb, vector<string>& result) {
        if (comb.size() == n * 2) {
            result.push_back(comb);
            return;
        }
        
        if (left < n){
            backtrack(n, left + 1, right, comb += "(", result);
            comb.pop_back();
        } 
        if (right < left){
            backtrack(n, left, right + 1, comb += ")", result);
            comb.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string comb;

        backtrack(n, 0, 0, comb, result);

        return result;
    }
};
