class Solution {
public:
    map<char, string> mpp;
    vector<string> ans; 

    void utility() {
        mpp['2'] = "abc"; mpp['3'] = "def"; mpp['4'] = "ghi";
        mpp['5'] = "jkl"; mpp['6'] = "mno"; mpp['7'] = "pqrs";
        mpp['8'] = "tuv"; mpp['9'] = "wxyz";
    }

    void dfs(int idx, string digits, string tmp) {
        if (idx == digits.size()) {
            ans.push_back(tmp);
            return;
        }


        for (auto ch : mpp[digits[idx]]) {
            dfs(idx + 1, digits, tmp + ch);    
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans; 
        utility();                     
        dfs(0, digits, "");  
        return ans;
    }
};
