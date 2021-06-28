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

//Build Tree From Preorder and INorder Traversal

node* buildTreeFromTraversal(int *in, int *pre, int s, int e)
{
	static int i = 0;
	// Base Case
	if (s > e)
	{
		return NULL;
	}

	node*root = new node(pre[i]);
	int index = -1;
	for (int j = s; j <= e; j++)
	{
		if (in[j] == pre[i])
		{
			index = j;
			break;
		}
	}
	i++;
	root->left = buildTreeFromTraversal(in, pre, s, index - 1);
	root->right = buildTreeFromTraversal(in, pre, index + 1, e);
	return root;
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
	int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
	int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	int n = sizeof(in) / sizeof(int);

	node* root = buildTreeFromTraversal(in, pre, 0, n - 1);
	print(root);
}