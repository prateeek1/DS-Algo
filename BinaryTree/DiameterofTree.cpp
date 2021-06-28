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
	print(root);
	cout << endl;
	replaceSum(root);
	print(root);


}