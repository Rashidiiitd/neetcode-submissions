class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int a = target[0];
        int b = target[1];
        int c = target[2];

        int wanta = 0;
        int wantb = 0;
        int wantc = 0;

        for(auto it : triplets)
        {
            if(it[0]>a || it[1]>b || it[2] > c) continue;

            wanta = max(it[0],wanta);
            wantb = max(it[1],wantb);
            wantc = max(it[2],wantc);
        }

        if(a == wanta && b == wantb && c== wantc) return true;

        return false;


    }
};
