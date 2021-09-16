class Solution {
public:

    int lca(string s)
    {
        int n = s.size();
        string s1 = s;
        string s2 = s;

        reverse(s2.begin(), s2.end());
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                dp[i][j] = (s1[i - 1] == s2[j - 1]) ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }


        return dp[n][n];
    }
    int maxProduct(string s) {

        int n = s.size();
        int ans = INT_MIN;

        for (int i = 0; i < (1 << n) - 1; i++)
        {
            string s1 = "";
            string s2 = "";

            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    s1.push_back(s[j]);

                else
                    s2.push_back(s[j]);
            }

            ans = max(ans, lca(s1) * lca(s2));
        }


        return ans;




    }
};