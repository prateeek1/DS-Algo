#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data = d;
		left == NULL;
		right == NULL;
	}
};

node* build()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	node* root = new node(d);
	root->left = build();
	root->right = build();

	return root;
}


node* lca(node*root, int a, int b)
{
	if (root == NULL)
		return NULL;

	if (root->data == a or root->data == b)
		return root;

	node* leftans = lca(root->left, a, b);
	node* rightans = lca(root->right, a, b);

	if (leftans != NULL && rightans != NULL)
		return root;

	if (leftans != NULL)
		return leftans;
	else
		return rightans;
}


// LEVEL OF THE GIVEN NODE
int search(node*root, int key, int level)
{
	if (root == NULL)
		return -1;

	if (root->data == key)
		return level;

	int left = search(root->left, key, level + 1);
	if (left != -1)
		return level;
	return search(root->right, key, level + 1);

}

//Function to find distance between two nodes
int findDistance(node*root, int a, int b)
{
	node* lca_node = lca(root, a, b);
	int l1 = search(lca_node, a, 0);
	int l2 = search(lca_node, b, 0);
	return l1 + l2;

}

void print(node*root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

int main()
{
	node*root = build();
	cout << findDistance(root, 10, 7);
}