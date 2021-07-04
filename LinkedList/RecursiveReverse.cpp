void helper(Node* &head, Node* prev, Node* curr)
{
    if (curr->next == NULL)  // if last element
    {
        head = curr;        // make it head
        curr->next = prev;  // link it's next to the previous element
        return;
    }

    Node* next = curr->next;
    curr->next = prev;      // link current node to previous node
    helper(head, curr, next); // current node will become previous and next node will become current
}

struct Node* reverseList(struct Node *head)
{
    helper(head, NULL, head);
    return head;
}
