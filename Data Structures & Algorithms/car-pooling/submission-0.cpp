class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int>diff(10001,0);

        for(auto it : trips)
        {
            int pass = it[0];
            int from = it[1];
            int to = it[2];
            diff[from] += pass;
            diff[to] -= pass;
        }
       
        int passenger  = 0;
        for(int i = 0;i<10001;i++)
        {
            passenger += diff[i];
            if(passenger>capacity) return false;
        }

        return true;
    }
};