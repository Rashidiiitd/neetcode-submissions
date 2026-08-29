class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0;
        for (char task : tasks) {
            freq[task - 'A']++;
            maxFreq = max(maxFreq, freq[task - 'A']);
        }
        
        int maxFreqCount = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxFreqCount++;
            }
        }
        
        int ans = (maxFreq - 1) * (n + 1) + maxFreqCount;
        
        return max((int)tasks.size(), ans);
    }
};
