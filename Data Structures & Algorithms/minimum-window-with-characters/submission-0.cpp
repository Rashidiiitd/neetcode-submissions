class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;

        for (char ch : t) {
            tmap[ch]++;
        }

        int targetMatches = tmap.size(); 
        int currentMatches = 0;         
        
        int len = INT_MAX;
        int start = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            smap[ch]++;

         
            if (tmap.count(ch) && smap[ch] == tmap[ch]) {
                currentMatches++;
            }


            while (currentMatches == targetMatches) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                smap[leftChar]--;

                if (tmap.count(leftChar) && smap[leftChar] < tmap[leftChar]) {
                    currentMatches--;
                }

                left++;
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
