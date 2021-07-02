Node* lca(Node* root , int n1 , int n2 )
{
   if (root == NULL)
      return NULL;

   if (root->data == n1 || root->data == n2) // If we find either n1 or n2 in node then this node id the LCA
      return root;


   Node* left = lca(root->left, n1, n2); // Traverse left and right child
   Node* right = lca(root->right, n1, n2);

   if (left != NULL && right != NULL) // If right and left both are not NULL then Lca is this node as left and right contains n1 and n2
      return root;

   if (left != NULL) // If n2 is not found left is Lca and vice versa
      return left;
   else
      return right;

}