class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        \


        int idx1 = lower_bound(nums, target); // find lower bound of target
        int idx2 = lower_bound(nums, target + 1) - 1; // find lower bound of target+1

        if (idx1 < nums.size() and nums[idx1] == target) // if index of target element is less than nums
            return {idx1, idx2};

        else
            return { -1, -1};

    }

    int lower_bound(vector<int>nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return low;
    }
};