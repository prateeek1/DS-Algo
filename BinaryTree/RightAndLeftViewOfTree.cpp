void helper(Node* root, int level, int &maxLevel, vector<int>&ans)
{
    if (root == NULL) // Level Means the current level of the tree
        return;         // Maxlevel is the maxlevel we traversed in the tree it's used so that we print only one root from every level

    if (maxLevel < level)
    {
        ans.push_back(root->data);
        maxLevel = level;
    }
    helper(root->right, level + 1, maxLevel, ans); // we traverse right first because we need the right view
    helper(root->left, level + 1, maxLevel, ans);

}
vector<int> rightView(Node *root)
{
    vector<int>ans;
    int maxLevel = 0;
    helper(root, 1, maxLevel, ans);
    return ans;
}

void helper(Node* root, int level, int &maxLevel, vector<int>&ans)
{
    if (root == NULL)
        return;

    if (maxLevel < level)
    {
        ans.push_back(root->data);
        maxLevel = level;
    }

    helper(root->left, level + 1, maxLevel, ans); // we traverse left first coz we need the left view
    helper(root->right, level + 1, maxLevel, ans);
}
vector<int> leftView(Node *root)
{
    vector<int>ans;
    int maxLevel = 0; // to store the maxlevel traversed travelled in the tree
    helper(root, 1, maxLevel, ans);
    return ans;
}