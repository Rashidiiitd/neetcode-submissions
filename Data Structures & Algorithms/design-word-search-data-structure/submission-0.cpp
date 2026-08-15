class Node {
public:
    char ch;
    Node* childList[26];
    int prefixCount;
    int isEnd;

    Node() {
        for (int i = 0; i < 26; i++) {
            childList[i] = nullptr;
        }
        prefixCount = 0;
        isEnd = 0;
    }
};

class WordDictionary {
    Node* trieNode;

    bool searchInNode(string& word, int index, Node* currIter) {
        if (index == word.length()) {
            return currIter->isEnd;
        }

        char it = word[index];

        if (it == '.') {
          
            for (int i = 0; i < 26; i++) {
                if (currIter->childList[i] != nullptr) {
                   
                    if (searchInNode(word, index + 1, currIter->childList[i])) {
                        return true; 
                    }
                }
            }
            return false;
        } 
        
        else {
            int charIdx = it - 'a';
            if (currIter->childList[charIdx] == nullptr) {
                return false; 
            }
            return searchInNode(word, index + 1, currIter->childList[charIdx]);
        }
    }

public:
    WordDictionary() { 
        trieNode = new Node(); 
    }

    void addWord(string word) {
        Node* currIter = trieNode;
        for (auto it : word) {
            if (currIter->childList[it - 'a'] == nullptr) {
                currIter->childList[it - 'a'] = new Node();
            }
            currIter = currIter->childList[it - 'a'];
        }
        currIter->isEnd = true;
    }

    bool search(string word) {
        return searchInNode(word, 0, trieNode);
    }
};
