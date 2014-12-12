class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return head;

        ListNode guard(0);
        guard.next = head;

        ListNode *boundary = &guard, *prev = &guard, *current = head; 
        while (current != NULL)
        {
            if (current->val < x) { 
                if (boundary == prev) {
                    boundary = prev = current;
                    current = current->next;
                    continue;
                }

                ListNode *bnext = boundary->next;
                ListNode *cnext = current->next;
                boundary->next = current;
                current->next = bnext;
                prev->next = cnext;

                boundary = current;
                current = cnext;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
        return guard.next;
    }
};
