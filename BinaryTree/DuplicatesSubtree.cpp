string helper(Node* root, unordered_map<string, int>&mp, vector<Node*>&ans)
{
    if (root == NULL)
        return "" ;

    string s = to_string(root->data) + "," + helper(root->right, mp, ans) + "," + helper(root->left, mp, ans);
    // string subtree is sum of root->data the data of left and right tree
    if (mp[s] == 1) // if frequency is already 1 so it's a duplicate
    {
        ans.push_back(root);
    }
    mp[s]++;  // Increase the frequency of the subtreee


    return s;


}
vector<Node*> printAllDups(Node* root)
{
    unordered_map<string, int>mp; // stores the frequency of subtrees
    vector<Node*>ans;  // Stores the root of duplicates subtrees
    helper(root, mp, ans);
    return ans;
}