class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int>mp;

        int n = nums.size();
        vector<int>v;

        for (int i = 0; i < n; i++)
        {
            int req = target - nums[i];

            if (mp.find(req) != mp.end())
            {
                v.push_back(i);
                v.push_back(mp[req]);
                return v;
            }

            mp[nums[i]] = i;
        }

        return v;


    }
};









