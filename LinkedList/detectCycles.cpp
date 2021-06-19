bool detectCycle(node* head)
{
	node*slow = head;
	node*fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)

			return true;
	}

	return false;


}


void removeLoop(Node* head)
{
	Node*slow = head;
	Node*fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
		{
			slow = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}

			while (fast->next != slow)
			{
				fast = fast->next;
			}
			fast->next = NULL;

		}
	}

}