vector<int> reverseLevelOrder(Node *root1)
{

   vector<int>ans;
   if (root1 == NULL)
      return ans;

   stack<Node*>s;  // Stack to push the traversed elements to get reverse order
   queue<Node*>q;  // Queue to traverse level order
   q.push(root1);


   while (!q.empty())
   {
      root1 = q.front();
      q.pop();
      s.push(root1);  // Push the root and check for left and right subtree

      if (root1->right) // Push right child first so that it is popped out last from stack to get left to right traversal
         q.push(root1->right);

      if (root1->left)
         q.push(root1->left);


   }

   while (!s.empty())
   {
      Node* root1 = s.top(); // Pop elements from stack to get reverse order
      ans.push_back(root1->data);
      s.pop();
   }



}