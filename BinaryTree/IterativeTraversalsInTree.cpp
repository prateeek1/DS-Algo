vector<int> postOrder(Node* root) {

    vector<int>ans;
    stack<Node*>s;
    stack<int >s2;  // Stack for Postorder traversal
    s.push(root);
    while (!s.empty())
    {
        Node* root = s.top(); // Push root in s2 as it is needed at last for postorder
        s2.push(root->data);
        s.pop();

        if (root->left)  // pushing left first in s so while popping it comes last and hence pushed last in s2 and can be popped first from there
            s.push(root->left);

        if (root->right)
            s.push(root->right);

    }
    while (!s2.empty())
    {
        int a = s2.top();
        ans.push_back(a);
        s2.pop();
    }

    return ans;
}




vector<int> inOrder(Node* root)
{
    vector<int>ans;
    stack<Node*>s;

    while (!s.empty() || root != NULL) // if stack is not empty or root is not null
    {
        if (root != NULL)
        {
            s.push(root);  // push all the left nodes in the stack
            root = root->left;
        }
        else
        {
            Node* a = s.top(); // if there are no left nodes we will pop the the last found left node and check for right nodes
            s.pop();
            ans.push_back(a->data);
            root = a->right;
        }
    }

    return ans;
}



vector<int> preOrder(Node* root)
{
    stack<Node*>s;
    vector<int>ans;
    s.push(root);

    while (!s.empty())
    {
        Node*a = s.top();
        s.pop();
        ans.push_back(a->data);

        if (a->right)
            s.push(a->right);

        if (a->left)
            s.push(a->left);

    }

    return ans;


}