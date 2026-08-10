class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string &s : strs) {
            encoded = encoded + to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int size = s.size();

        while(i < size) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));

            ans.push_back(s.substr(j + 1, length));

            i = j + 1 + length;
        }

        return ans;
    }
};
