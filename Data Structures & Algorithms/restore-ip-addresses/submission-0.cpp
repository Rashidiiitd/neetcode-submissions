class Solution {
private:
    bool isValid(string tmp) {
        int len = tmp.size();
        if (len == 0 || len > 3) return false;
        
        if (len > 1 && tmp[0] == '0') return false; 
        
        int num = stoi(tmp);
        return num <= 255;
    }

public:
    void func(int idx, string s, int octetCount, string &currentIP, vector<string> &ans) {
        if (idx == s.size() && octetCount == 4) {
            currentIP.pop_back(); 
            ans.push_back(currentIP);
            currentIP.push_back('.'); 
            return;
        }
        
        if (octetCount >= 4 || idx >= s.size()) return;

        for (int cut = idx; cut < idx + 3 && cut < s.size(); cut++) {
            int len = cut - idx + 1;
            string tmp = s.substr(idx, len); 
            
            if (isValid(tmp)) {
              
                int originalSize = currentIP.size(); 
                currentIP += tmp + '.'; 
                

                func(cut + 1, s, octetCount + 1, currentIP, ans);


                currentIP.resize(originalSize); 
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 || s.size() < 4) return vector<string>();
        
        vector<string> ans;
        string currentIP = "";
        
        func(0, s, 0, currentIP, ans);
        
        return ans;
    }
};
