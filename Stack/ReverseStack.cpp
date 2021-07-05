#include<iostream>
#include<stack>
using namespace std;



void transfer(stack<int>&s1, stack<int>&s2, int n)
{
	for (int i = 0; i < n; i++)
	{
		int a = s1.top();
		s2.push(a);
		s1.pop();
	}
}


void insertAtBottom(stack<int>&s, int x)
{
	if (s.empty())
	{
		s.push(x);
		return;
	}
	// rec case
	int data = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(data);
}


void reverseStack(stack<int>&s)
{
	if (s.empty())
		return;
	int x = s.top();
	s.pop();
	// recursively reverse the smaller stack
	reverseStack(s);
	//insert the element x at the bottom of stack
	insertAtBottom(s, x);
}

int main()
{
	stack<int>s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);

	reverseStack(s1);
	while (!s1.empty())
	{
		cout << s1.top() << endl;
		s1.pop();
	}
}