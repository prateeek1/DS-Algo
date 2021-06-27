int maxDepth(TreeNode* root) {


    if (root == NULL)
        return 0;


    int left = maxDepth(root->right);
    int right = maxDepth(root->left);

    return max(left, right) + 1;

}