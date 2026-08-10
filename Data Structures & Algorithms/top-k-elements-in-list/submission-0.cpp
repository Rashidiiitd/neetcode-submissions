class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        unordered_map<int,int>mpp;
        for(auto x : nums){
            mpp[x]++;
            //cout<<mpp[x]<<endl;
        }
        for(auto it : mpp){
            cout<<it.first<<"->";
            cout<<it.second<<endl;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         for(auto x: mpp){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }

            
         }

vector<int>ans;
while(!pq.empty()){
    auto top = pq.top();
    ans.push_back(top.second);
    pq.pop();
}
        return ans;

    }
};