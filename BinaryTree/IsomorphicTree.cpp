bool isIsomorphic(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 0;

    if (root1 == NULL or root2 == NULL) // if any one node is NULL and other not then return false
        return false;

    queue<Node*>q1, q2;
    q1.push(root1);
    q2.push(root2);
    int level = 0;
    vector<int>v;
    unordered_map<int, int>mp; // stores count of root->values

    while (!q1.empty() && !q2.empty())
    {
        if (q1.size() != q2.size()) // if size is not same in same level return false
            return false;
        level++;
        v.clear();
        mp.clear(); // clear for every level the values in map
        int size = q1.size();
        while (size--)
        {

            Node* temp1 = q1.front();
            Node* temp2 = q2.front();
            q1.pop();
            q2.pop();
            if (mp.find(temp1->data) == mp.end())  // if data not in map then store it
                mp[temp1->data] = 1;
            else
                mp[temp1->data]++;   // if already in map then count++
            v.push_back(temp2->data);
            if (temp1->left)
                q1.push(temp1->left);
            if (temp1->right)
                q1.push(temp1->right);
            if (temp2->left)
                q2.push(temp2->left);
            if (temp2->right)
                q2.push(temp2->right);
        }


        for (auto i : v)
        {
            if (mp.find(i) == mp.end())
                return false;

            else
            {
                mp[i]--;   // reduce the count in map for every val in vector
                if (mp[i] < 0)
                    return false;
                else if (mp[i] == 0) // if count is zero then erase the element
                    mp.erase(i);
            }
        }


        if (mp.size() != 0) // if size not zero then false otherwise true
            return false;


    }

    return true;
}