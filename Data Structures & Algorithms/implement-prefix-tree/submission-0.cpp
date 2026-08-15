#include <string>

using namespace std;

class Node
{
public:
    char ch; 
    Node* childList[26];
    int prefixCount;
    int isEnd;

    Node()
    {
        for(int i = 0; i < 26; i++)
        {
            childList[i] = nullptr;
        }

        prefixCount = 0;
        isEnd = 0;
    }
};


class PrefixTree {
    Node *trieNode;
public:
    PrefixTree() {
        trieNode = new Node();
    }
    
    void insert(string word) {
        Node *currIter = trieNode;
        
        for(auto it : word)
        {
            if(currIter->childList[it - 'a'] == nullptr)
            {
                currIter->childList[it - 'a'] = new Node();
            }
            currIter = currIter->childList[it - 'a'];
        }

        currIter->isEnd = true;
    }
    
    bool search(string word) {
        Node *currIter = trieNode;
        
        for(auto it : word)
        {
            if(currIter->childList[it - 'a'] == nullptr)
            {
                return false;
            }
            currIter = currIter->childList[it - 'a'];
        }

        return currIter->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *currIter = trieNode;
        
        for(auto it : prefix)
        {
            if(currIter->childList[it - 'a'] == nullptr)
            {
                return false;
            }
            currIter = currIter->childList[it - 'a'];
        }

        return true;
    }
};
