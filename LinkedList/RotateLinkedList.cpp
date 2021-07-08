class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // edge cases
        if (!head || !head->next || k == 0)
            return head;

        // find the length
        ListNode* curr = head;
        int len = 1;
        while (curr->next)
        {
            len++;
            curr = curr->next;
        }

        // Make the lst node point to head
        curr->next = head;


        // go to that node
        k = k % len;
        k = len - k; // Node which will be the head after rotation -1

        while (k--)
            curr = curr->next;


        head = curr->next;
        curr->next = NULL;

        return head;



    }
};








































