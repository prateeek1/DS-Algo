int helper(Node*root)
{
    if (root == NULL)
        return 0;
    int temp = root->data; // store old value

    root->data = helper(root->left) + helper(root->right); // update the value

    return temp + root->data; // return for upper level
}
void toSumTree(Node *root)
{
    helper(root);

}