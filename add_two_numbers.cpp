class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode **plast = &head;
        int carry = 0, sum;
        int a, b;

        while(l1 != NULL || l2 != NULL)
        {
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;

            sum = a + b + carry;
            carry = sum / 10;
            *plast = new ListNode(sum % 10);
            plast = &((*plast)->next);

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if (carry) 
        {
            *plast = new ListNode(carry);
            plast = &((*plast)->next);
        }
        *plast = NULL;

        return head;
    }
};
