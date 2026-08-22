class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;

    void Utility(vector<string>& wordDict) {
        for (auto it : wordDict) {
            st.insert(it);
        }
    }

    void dfs(string &s, string &curr, int idx) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }
         
        for (int cut = idx; cut < s.size(); cut++) {
            int len = cut - idx + 1;
            string tmp = s.substr(idx, len);

            if (!st.count(tmp)) {
                continue;
            }

            string rollBack = curr;
            if (curr.empty()) {
                curr = tmp;
            } else {
                curr = curr + " " + tmp;
            }

            dfs(s, curr, cut + 1); 

            curr = rollBack;
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Utility(wordDict);
        string curr = "";
        dfs(s, curr, 0);
        return ans;
    }
};
