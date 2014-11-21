class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (NULL == head) return head;

        ListNode *p = head;
        ListNode *q = head->next;

        while (q != NULL)
        {
            if (q->val == p->val)
            {
                q = q->next;
            }
            else
            {
                p = p->next;
                p->val = q->val;
                q = q->next;
            }
        }

        p->next = NULL;
        
        return head;
    }
};
