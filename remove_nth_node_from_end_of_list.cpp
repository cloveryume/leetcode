class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (NULL == head) return head;

        ListNode *p = head, *q = head;
        
        // q 移到 p 前面n位
        for (int i = 0; i < n; ++i)
        {
            if (NULL == q) break;
            q = q->next;
        }

        if (NULL == q) // 删除的是head
        {
            head = head->next;
            return head;
        }

        while(q && q->next) // q移到末尾
        {
            p = p->next;
            q = q->next;
        }

        // 删除p的下一个节点
        p->next = p->next->next;

        //TODO free or delete

        return head; 
    }
};
