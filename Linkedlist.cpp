#include<bits/stdc++.h>
using namespace std;


class node
{
public:
	int data;
	node* next;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};


int length(node* head)     //length of linked list
{
	int cnt = 0;
	while (head)
	{
		cnt++;
		head = head->next;
	}
	return cnt;
}

void insertAtHead(node* &head, int d)   //insertion at head
{
	if (head == NULL)
	{
		head = new node(d);
		return;
	}
	node* n = new node(d);
	n->next = head;
	head = n;

}


void insertAtTail(node* &head, int d)  //insertion at tail
{
	if (head == NULL)
	{
		head = new node(d);
		return;
	}

	node*temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	node *n = new node(d);
	temp->next = n;
}


void insertInMiddle(node* &head, int d, int p)  //insertion in middle
{
	if (head == NULL || p == 0)
	{
		insertAtHead(head, d);
		return;
	}
	else if (p > length(head))
	{
		insertAtTail(head, d);
	}
	else
	{
		node*temp = head;
		int jump = 1;
		while (jump <= p - 1)
		{
			jump++;
			temp = temp -> next;
		}

		node*n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}

}



void print(node* head) //print linked list
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}


void deleteHead(node* head)   //delete head
{
	if (head == NULL)
	{
		return;
	}
	node* temp = head->next;
	delete head;
	head = temp;
}


bool search(node*head, int key)  //linear search in ll
{
	node*temp = head;
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}


bool searchRecursive(node*head, int key) // recursive search
{
	if (head == NULL)
		return false;

	if (head->data == key)return true;

	else
		searchRecursive(head->next, key);
}



void reverse(node* &head)   // reverse a linked list
{
	node*prev = NULL;
	node*curr = head;
	node*next = NULL;

	while (curr)
	{
		next = curr->next;  //save the next node
		curr->next = prev;  // make current node point to previous
		prev = curr;    // update  p and c
		curr = next;
	}

	head = prev;

}



node* recReverse(node*head)
{
	if (head->next == NULL or head == NULL)
		return head;

	node*shead = recReverse(head->next);

	head->next->next = head;
	head->next = NULL;
	return shead;
}

node* input()
{
	int d;
	node* head = NULL;
	while (cin >> d)
	{
		insertAtTail(head, d);
	}
	return head;
}


int main()
{
	node *head = input();



	insertInMiddle(head, 5, 1);
	print(head);
	cout << endl;
	cout << searchRecursive(head, 5) << endl;
	reverse(head);
	print(head);


}
