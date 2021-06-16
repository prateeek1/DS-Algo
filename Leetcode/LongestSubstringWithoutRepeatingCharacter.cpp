class Solution {
public:
    int lengthOfLongestSubstring(string s) {



        int n = s.length();

        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        vector<int>a(256, -1); // Stores all Characters

        int i = 0;
        int ans = 0;
        for (int j = 0; j < n; j++)
        {

            i = max(i, a[s[j] - NULL] + 1); // Last position of the current element max is used to avoid -1

            ans = max(ans, j - i + 1); // Maximaising the length

            a[s[j] - NULL] = j; // Making the last seen  position of current element as curr index
        }

        return ans;

    }
};