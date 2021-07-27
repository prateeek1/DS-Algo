class Solution {
public:
    vector<string> generateParenthesis(int n) {


        vector<string>ans;

        permute(0, 0, n, ans, "");
        return ans;
    }

    void permute(int open, int close, int n, vector<string>&ans, string curr)
    {
        if (open + close == 2 * n)
        {
            ans.push_back(curr);
        }

        if (open < n)
        {
            permute(open + 1, close, n, ans, curr + "(");
        }

        if (close < open)
        {
            permute(open, close + 1, n, ans, curr + ")");
        }
    }
};