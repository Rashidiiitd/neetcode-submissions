struct Node
{
    Node *links[26] = {}; 
};

class Solution {
public:
    Node *root;
    Solution()
    {
        root = new Node();
    }

    void insert(string prefix)
    {
        Node *currNode = root;
        for(auto it : prefix)
        {
         
            if (currNode->links[it - 'a'] == nullptr) {
                currNode->links[it - 'a'] = new Node();
            }
            currNode = currNode->links[it - 'a']; 
        }
    }

    int getMaxPrefix(string s)
    {
        int i = 0;
        Node *currNode = root;
        for(auto it : s)
        {
          
            if(currNode->links[it - 'a'] == nullptr) return i; 
            currNode = currNode->links[it - 'a'];
            i++;
        }
        return i;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; 
        insert(strs[0]);
         
        string prefix = strs[0];
        int maxLen = prefix.length(); 

        for(int i = 1; i < strs.size(); i++)
        {
        
            maxLen = min(maxLen, getMaxPrefix(strs[i]));
        }

        return prefix.substr(0, maxLen);
    }
};
