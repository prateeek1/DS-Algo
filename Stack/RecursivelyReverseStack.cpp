#include<iostream>
#include<stack>
using namespace std;

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