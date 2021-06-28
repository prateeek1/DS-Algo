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

// Print Right View

void PrintRightView(node* root, int level, int & maxLevel)
{
	if (root == NULL)
		return;

	if (level > maxLevel)
	{
		cout << root->data << " ";
		maxLevel = level;
	}

	PrintRightView(root->right, level + 1, maxLevel);
	PrintRightView(root->left, level + 1, maxLevel);
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
	int maxLevel = -1;

	PrintRightView(root, 0, maxLevel);
}