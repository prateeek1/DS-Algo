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

void bfs(node*root)
{
	queue<node*>q;
	q.push(root);

	while (!q.empty())
	{
		node* a = q.front();
		cout << a->data << " ";

		q.pop();
		if (a->left)
		{
			q.push(a->left);
		}
		if (a->right)
		{
			q.push(a->right);
		}

	}
}




int main()
{

	node* root = build();
	bfs(root);

}