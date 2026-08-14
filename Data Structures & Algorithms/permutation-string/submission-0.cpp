class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }

        if (s1_count == window_count) return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            window_count[s2[i] - 'a']++;
            window_count[s2[i - s1.size()] - 'a']--;

            if (s1_count == window_count) return true;
        }

        return false;
    }
};
