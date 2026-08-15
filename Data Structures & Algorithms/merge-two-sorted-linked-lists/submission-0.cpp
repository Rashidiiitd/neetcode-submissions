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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* headFirst = list1;
        ListNode* headSecond = list2;

        ListNode* newHead = new ListNode(-1);
        ListNode *iter = newHead;

        if(newHead == nullptr)
        {
            
            if(list1)
            {
                return list1;
            }

            return list2;
        }

        while(headFirst && headSecond)
        {
            if(headFirst->val<headSecond->val)
            {
                iter->next = headFirst;
                headFirst = headFirst->next;
            }
            else
            {
                iter->next = headSecond;
                headSecond = headSecond->next;
            }
            iter = iter->next;

        }

        if(headFirst)
        {
            iter->next = headFirst;
        }
        else
        {
            iter->next = headSecond;
        }

        return newHead->next;

    }
};
