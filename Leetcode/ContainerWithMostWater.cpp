class Solution {
public:
    int maxArea(vector<int>& a) {

        int n = a.size();
        int low = 0;
        int high = n - 1;
        int ans = 0;
        while (low < high)
        {

            ans = max(ans, min(a[low], a[high]) * (high - low));

            if (a[low] < a[high])
                low++;
            else
                high--;

        }
        return ans;

    }
};