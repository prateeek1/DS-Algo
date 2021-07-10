class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        string ans = "";
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0) // substring of length 1 will always be palindrome
                {
                    dp[i][j] = 1;
                }

                else if (gap == 1) // check for substring of length 2
                {
                    if (s[i] == s[j])
                        dp[i][j] = 1;
                }

                else  // check for substring of length >2
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                        dp[i][j] = 1;
                }

                if (dp[i][j])
                {
                    if (ans.length() < j - i + 1)
                        ans = s.substr(i, j - i + 1);
                }
            }
        }

        return ans;




    }





};