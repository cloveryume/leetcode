class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBST(head, calListLength(head));
    }

private:
    int calListLength(ListNode *head) {
        int length = 0;
        while (head != NULL) { ++length; head = head->next; }
        return length;
    }

    ListNode *advance(ListNode *head, int len)
    {
        ListNode *ret = head;
        while (len-- > 0) ret = ret->next;
        return ret;
    }

    TreeNode *sortedListToBST(ListNode *head, int len) {
        if (0 == len) return NULL;

        ListNode *mid = advance(head, len/2);

        TreeNode *node = new TreeNode(mid->val);
        node->left = sortedListToBST(head, len/2);
        node->right = sortedListToBST(mid->next, len - len/2- 1);

        return node;
    }
};
