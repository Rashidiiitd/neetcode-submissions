class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        
        int size = hand.size();
        if(size % k) return false;

        if(k == 1) return true;

        map<int, int> mpp;

        for(auto it : hand)
        {
            mpp[it]++;
        }

        while(!mpp.empty())
        {
            auto [key, value] = *mpp.begin();
            
            for(int i = 0; i < k; i++)
            {
                int nextCard = key + i;
                
                if(mpp.find(nextCard) == mpp.end())
                {
                   return false;
                }

                mpp[nextCard]--;
                
                if(mpp[nextCard] == 0)
                {
                    mpp.erase(nextCard);
                }
            }
        }

        return true; 
    }
};
