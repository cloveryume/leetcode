class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (NULL == head || NULL == head->next) return false;
        
        ListNode *slow = head, *fast = head;
        bool has = false;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                has = true;
                break;
            }
        }

        return has;
    }
};
