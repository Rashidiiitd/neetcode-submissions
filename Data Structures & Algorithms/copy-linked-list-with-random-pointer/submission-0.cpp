/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*,Node*>mpp;

        Node *iter = head;
        while(iter)
        {
            Node *newNode = new Node(iter->val);

            mpp[iter] = newNode;
            iter = iter->next;
        }

        iter = head;
       Node *newHead = new Node(-1);
       Node *nHead = newHead;

       while(iter)
       {
           newHead->next = mpp[iter];
           newHead = newHead->next;
           newHead->next = mpp[iter->next];
           newHead->random = mpp[iter->random];

           iter = iter->next;
       }
      return nHead->next;

    }
    
};