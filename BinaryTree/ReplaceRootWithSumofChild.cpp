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

int replaceSum(node*root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
	{
		return root->data;
	}

	int leftsum = replaceSum(root->left);
	int rightsum = replaceSum(root->right);

	int temp = root->data;
	root->data = leftsum + rightsum;

	return temp + root->data;

}

// Height Balanced Tree
// At each node height of left tree and right tree is zero or 1
// Function to Check Whether Tree is Height Balanced or not
class HBpair
{
public:
	int height;
	bool balance;
};

HBpair isHeightBalanced(node*root)
{
	HBpair p;
	if (root == NULL)
	{
		p.height = 0;
		p.balance = true;
		return p;
	}
	HBpair left = isHeightBalanced(root->left);
	HBpair right = isHeightBalanced(root->right);

	p.height = max(left.height, right.height) + 1;
	if (abs(left.height - right.height) <= 1 && left.balance && right.balance)
	{
		p.balance = true;
	}
	else
		p.balance = false;

	return p;
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

	node* root = build();
	if (isHeightBalanced(root).balance)
		cout << "balance";
	else
		cout << "NOt";




}