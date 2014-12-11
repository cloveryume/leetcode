#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL ) return head;

        ListNode guard(0);
        guard.next = head;

        ListNode *p = head, *q = head->next;
        ListNode *prev = &guard;
        while (true) {
            ListNode *next_q = q->next;

            prev->next = q;
            q->next = p;
            p->next = next_q;

            if (next_q == NULL || next_q->next == NULL) break;

            prev = p;
            p = next_q;
            q = next_q->next;
        }

        return guard.next;
    }
};
