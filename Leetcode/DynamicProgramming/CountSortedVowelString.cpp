class Solution {
public:
    int countVowelStrings(int n) {
        if (n == 0)
            return 0;  // If length is zero return

        vector<vector<int>>dp(n + 1, vector<int>(5, -1));
        return helper(n, 0, dp); // Helper function gets length , start and dp

    }

    int helper(int n, int i, vector<vector<int>>&dp)
    {
        if (i == 5) // If all the 5 vowels are seen return 0
            return 0;

        if (n == 0) // If valid ans is found
            return 1;

        if (dp[n][i] != -1)
            return dp[n][i];


        dp[n][i] = helper(n - 1, i, dp) + helper(n, i + 1, dp); // Add Vowels+ Skip Vowels

        return dp[n][i];
    }


};