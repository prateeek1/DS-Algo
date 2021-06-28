class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        int ans = INT_MIN;
        int val = 1;
        int realans = 1;
        while (!q.empty())
        {
            TreeNode* a = q.front();
            if (a == NULL)
            {

                q.pop();
                //cout<<sum<<endl;
                if (sum > ans)
                {
                    ans = sum;
                    realans = val;
                }
                if (!q.empty())
                {
                    q.push(NULL);
                    val++;
                }
                sum = 0;
            }
            else
            {
                q.pop();
                sum += a->val;
                if (a->left)
                    q.push(a->left);
                if (a->right)
                    q.push(a->right);
            }
        }

        //cout<<ans<<endl;

        return realans;

    }
};