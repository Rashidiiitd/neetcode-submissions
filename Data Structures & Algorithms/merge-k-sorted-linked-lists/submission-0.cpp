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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    
        
       priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

       for(auto it : lists)
       {
        if(it == nullptr ) continue;
        pq.push({it->val,it});
       }

    ListNode *newHead = new ListNode(-1);
    ListNode *iter = newHead;
       while(!pq.empty())
       {
          auto [val,node] = pq.top(); pq.pop();
          iter->next = node;
          iter = iter->next;

          if(node->next)
          {

            pq.push({node->next->val,node->next});
          }
       }

    //    delete iter;
       return newHead->next;
    }
};
