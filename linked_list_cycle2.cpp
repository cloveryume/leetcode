class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        ListNode *meet = NULL; // 第一次相遇的结点
        int count = 0;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                meet = slow;
                break;
            }
        }

        if (NULL == meet) return NULL;

        ListNode *start = head;
        while(start != meet)
        {
            start = start->next;
            meet = meet->next;
        }

        return start;
    }
};
