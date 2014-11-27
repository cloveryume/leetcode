class Solution {
public:
    void reorderList(ListNode *head) {
        if (NULL == head || NULL == head->next) return;

        ListNode *mid = head, *fast = head->next;
        // 找到位于中间的结点
        while (fast != NULL && fast->next != NULL)
        {
            mid = mid->next;
            fast = fast->next->next;
        }

        // 把中间结点以后的结点放入栈中
        stack<ListNode *> nodes;
        ListNode *p = mid->next, *q;
        while (p != NULL)
        {
            nodes.push(p);
            p = p->next;
        }
        mid->next = NULL;

        // 栈中的结点依次插入前面结点中
        p = head;
        while (p != NULL && !nodes.empty())
        {
            q = p;
            p = p->next;
            q->next = nodes.top();
            nodes.pop();
            q->next->next = p;
        }
    }
};
