class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for (auto x : s) {
            freq[x - 'a']++;
        }
        
        priority_queue<pair<int, int>> pq;
        string ans = "";
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], i});
            }
        }
        
        while (!pq.empty()) {
            vector<pair<int, int>> tmp;
            int size = pq.size();
            
            if (size == 1 && pq.top().first > 1) return "";
            
            int limit = min(2, size);
            for (int i = 1; i <= limit; i++) {
                auto [freq, ch] = pq.top();
                pq.pop();
                ans += ('a' + ch);
                freq--;
               
                if (freq > 0) tmp.push_back({freq, ch});
            }
            
            for (auto it : tmp) {
                pq.push(it);
            }
        }
        
        return ans;
    }
};
