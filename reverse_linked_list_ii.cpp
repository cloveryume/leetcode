class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (n - m == 0) return head;

        ListNode guard(0);
        guard.next = head;

        //找到开始结点及其前面的结点
        ListNode *start = head, *prev = &guard;
        for (int i = 0; i < m - 1; ++i)
        {
            prev = start;
            start = start->next;
        }

        // 逆序m 到 n 之间的结点
        ListNode *p = start->next, *q = start, *s;
        for (int i = 0; i < n - m; ++i)
        {
            s = p->next;
            p->next = q;
            q = p;
            p = s;
        }

        //拼接
        prev->next = q;
        start->next = p;

        return guard.next;
    }
};
