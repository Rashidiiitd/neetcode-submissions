class TimeMap {
public:
   unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        
        int len = mpp[key].size();

        const auto &tmp = mpp[key];

        int low = 0;
        int high = len-1;
        string ans = "";

        while(low<=high)
        {
           int  mid = low + (high-low)/2;
            if(tmp[mid].first==timestamp)
            {
               return tmp[mid].second;
            }
            else if(tmp[mid].first < timestamp)
            {
              ans = tmp[mid].second;
              // try to find better option
              low = mid+1;
            }
            else
            {
                high = mid-1;
            }

        }

        return ans;
    }
};
