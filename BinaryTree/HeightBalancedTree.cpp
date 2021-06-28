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

// Build a Height Balanced Tree From given Array
node* buildFromArray(int a[], int s, int e)
{
	if (s > e)
	{
		return NULL;

	}
	int mid = (s + e) / 2;
	node* root = new node(a[mid]);

	root->left = buildFromArray(a, s, mid - 1);
	root->right = buildFromArray(a, mid + 1, e);
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
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int n = 7;

	node* root = buildFromArray(a, 0, 6);
	print(root);





}