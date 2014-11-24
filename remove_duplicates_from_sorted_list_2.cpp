class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (NULL == head) return head;

        ListNode *guard = new ListNode(head->val + 1);
        guard->next = head;

        ListNode *prev_p = guard;
        ListNode *p = head, *q = head->next;
        int count = 0;
        while (q != NULL)
        {
            if (q->val == p->val)
            {
                ++count;
            }
            else
            {
                if (count > 0)
                {
                    prev_p->next = q;
                    p = q;
                }
                else
                {
                    prev_p = p;
                    p = q;
                }
                count = 0;
            }

            q = q->next;
        }

        //last
        if (count > 0) prev_p->next = q; 

        head = guard->next;
        delete guard;

        return head;
    }
};
