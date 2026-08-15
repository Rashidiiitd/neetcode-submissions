/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *slow = head;
        ListNode *fast = head;

        for(int i = 1;i<=n;i++)
        {
            fast = fast->next;
            if(fast == nullptr) return head->next;
        }

       ListNode *prev = slow;
    //    prev->next = slow;
        while(fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

       prev->next = slow->next;
       slow->next = nullptr;
       delete slow;

       return head;

    }
};
