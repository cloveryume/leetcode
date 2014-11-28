class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (NULL == headA || NULL == headB) return NULL;

        ListNode *p = headA;
        while (p->next != NULL) p = p->next;
        p->next = headA;

        ListNode *ret = getCycleEntry(headB);
        p->next = NULL;
        return ret;
    }

private:
    ListNode *getCycleEntry(ListNode *head) {
        ListNode *slow = head, *fast = head;
        ListNode *meet = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { meet = slow; break; }
        }

        if (NULL == meet) return NULL;

        ListNode *p = head, *q = meet;
        while (p != q)
        {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};
