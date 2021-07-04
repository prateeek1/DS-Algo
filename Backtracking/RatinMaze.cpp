class Solution {
public:
    void helper(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[])
    {
        if (i == n - 1 and j == n - 1)
        {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int index = 0; index < 4; index++)
        {
            int nexti = i + di[index];
            int nextj = j + dj[index];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && m[nexti][nextj] == 1 && !vis[nexti][nextj])
            {
                vis[i][j] = 1;
                helper(nexti, nextj, m, n, ans, move + dir[index], vis, di, dj);
                vis[i][j] = 0;
            }
        }


    }
    vector<string> findPath(vector<vector<int>> &m, int n) {

        vector<string>ans;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};

        if (m[0][0] == 1)
            helper(0, 0, m, n, ans, "", vis, di, dj);
        return ans;
    }



};