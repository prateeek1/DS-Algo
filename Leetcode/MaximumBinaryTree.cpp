TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

    return (helper(nums, 0, nums.size()));

}

TreeNode* helper(vector<int>nums, int l, int r)
{
    if (l == r)
        return NULL;

    int idx = maxi(nums, l, r);
    TreeNode* root = new TreeNode(nums[idx]);

    root->left = helper(nums, l, idx);
    root->right = helper(nums, idx + 1, r);

    return root;
}


int maxi(vector<int>nums, int l, int r)
{

    int m = INT_MIN;
    int idx = 0;
    for (int i = l; i < r; i++)
    {
        if (nums[i] > m)
        {
            m = nums[i];
            idx = i;
        }
    }

    return idx;
}