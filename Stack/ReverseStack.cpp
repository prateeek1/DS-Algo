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



void reverseStack(stack<int>&s1)
{
	stack<int>s2;
	int n = s1.size();
	for (int i = 0; i < n; i++)
	{
		// pick the element from top and insert at bottom
		int x = s1.top();
		s1.pop();

		// tansfer n-i-1 elemnts from s1 to s2
		transfer(s1, s2, n - i - 1);

		// insert the element x in s1
		s1.push(x);

		// transfer the element from s2 to s1
		transfer(s2, s1, n - i - 1);
	}
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