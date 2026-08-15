class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //l1 = reverse(l1);
       // l2 = reverse(l2);

        int carry = 0;
        ListNode* newHead = new ListNode(-1);
        ListNode* tail = newHead;

        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return newHead->next;
    }
};
