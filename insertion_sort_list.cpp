class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (NULL == head || NULL == head->next) return head;

        ListNode *cur = head->next;
        ListNode *prev = head;
        while (cur != NULL)
        {
            // 搜索第一个大于 cur->val 的位置
            ListNode *cur_q = head;
            ListNode *prev_q = NULL;
            while(cur_q != cur)
            {
                if (cur_q->val > cur->val)
                    break;

                prev_q = cur_q;
                cur_q = cur_q->next;
            }

            if (cur == cur_q)   // 没有找到
            {
                prev = cur;
                cur = cur->next;
            }
            else
            {
                //删除 cur
                prev->next = cur->next;

                // 插入到 q 前面
                if (NULL == prev_q)
                {
                    cur->next = head;
                    head = cur;
                }
                else
                {
                    prev_q->next = cur;
                    cur->next = cur_q;
                }

                cur = prev->next;
            }
        }

        return head;
    }
};
