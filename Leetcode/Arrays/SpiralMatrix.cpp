class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int>ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int rowBegin = 0;
        int rowEnd = n - 1;
        int colBegin = 0;
        int colEnd = m - 1;

        while (rowBegin <= rowEnd and colBegin <= colEnd)
        {

            for (int i = colBegin; i <= colEnd; i++)
            {
                ans.push_back(matrix[rowBegin][i]);

            }
            rowBegin++;

            for (int i = rowBegin; i <= rowEnd; i++)
            {
                ans.push_back(matrix[i][colEnd]);

            }
            colEnd--;

            for (int i = colEnd; i >= colBegin; i--)
            {
                if (rowBegin <= rowEnd)
                    ans.push_back(matrix[rowEnd][i]);

            }
            rowEnd--;

            for (int i = rowEnd; i >= rowBegin; i--)
            {
                if (colBegin <= colEnd)
                    ans.push_back(matrix[i][colBegin]);
            }
            colBegin++;

        }

        return ans;


    }
};