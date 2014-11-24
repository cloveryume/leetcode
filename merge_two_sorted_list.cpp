class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode **plast = &head;

        ListNode *node;
        while (l1 || l2)
        {
            if (!l1) 
            {
                node = l2; 
                l2 = l2->next;
            }
            else if (!l2)  
            {
                node = l1; 
                l1 = l1->next;
            }
            else if (l1->val > l2->val) {
                node = l2;
                l2 = l2->next;
            }
            else
            {
                node = l1;
                l1 = l1->next;
            }

            *plast = node;
            plast = &(node->next);
        }

        *plast = NULL;

        return head;
    }
}
