void helper(Node*root, int d, int h, map<int, pair<int, int>>&mp)
{
    if (root == NULL)
        return ;

    if (mp.count(d) == 0) // if there is no node with current distance we insert it in map
        mp[d] = {root->data, h};

    if (mp[d].second <= h) // if there is a node with same distance but height is greater than or equal to the node in map we replace the node with node in map
        mp[d] = {root->data, h};

    helper(root->left, d - 1, h + 1, mp); // distance decrease as we go in left direction and vice versa
    helper(root->right, d + 1, h + 1, mp);

}

vector<int> bottomView(Node *root)
{
    map<int, pair<int, int>>mp; // map<horizontal distance,pair<root->data,height>>

    helper(root, 0, 0, mp);

    vector<int>ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
        ans.push_back(it->second.first);

    return ans;
}










void helper(Node*root, int d, int h, map<int, pair<int, int>>&mp)
{
    if (root == NULL)
        return ;

    if (mp.count(d) == 0) // if there is no node with current distance we insert it in map
        mp[d] = {root->data, h};

    if (mp[d].second > h) // if there is a node with same distance but height is less than node in map we replace the node with node in map
        mp[d] = {root->data, h};

    helper(root->left, d - 1, h + 1, mp); // distance decrease as we go in left direction and vice versa
    helper(root->right, d + 1, h + 1, mp);

}

vector<int> topView(Node *root)
{
    map<int, pair<int, int>>mp; // map<horizontal distance,pair<root->data,height>>

    helper(root, 0, 0, mp);

    vector<int>ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
        ans.push_back(it->second.first);

    return ans;
}