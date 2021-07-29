class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows * cols - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            int mid_val = matrix[mid / cols][mid % cols];

            if (mid_val == target)
                return true;

            if (mid_val < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return false;
    }
};