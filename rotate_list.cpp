class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
       if (NULL == head || NULL == head->next) return head; 
       if (0 == k) return head;
        
       int size = 0;
       ListNode *slow = head, *fast = head;
       while (fast != NULL)
       {
           fast = fast->next;
           ++size;
           if (--k == 0) break;
       }

       // k 大于链表长度，重新计算k
       if (NULL == fast) 
       {
           k %= size;
           if (k == 0) return head;

           return rotateRight(head, k);
       }

       while (fast->next != NULL)
       {
           slow = slow->next;
           fast = fast->next;
       }

       fast->next = head;
       head = slow->next;
       slow->next = NULL;
    
       return head;
    }
};
