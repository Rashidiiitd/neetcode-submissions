class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            vector<pair<int, char>> tmp;
            int limit = min(2, (int)pq.size());

            for (int i = 1; i <= limit; i++) {
                auto [freq, ch] = pq.top();
                pq.pop();

                if (i == 1 && freq >= 2 && (ans.empty() || ans.back() != ch)) {
                    ans += ch;
                    ans += ch;
                    freq -= 2;
                } else {
                    ans += ch;
                    freq -= 1;
                }

                if (freq > 0) tmp.push_back({freq, ch});
            }

            if (limit == 1) break;

            for (auto it : tmp) pq.push(it);
        }

        return ans;
    }
};
