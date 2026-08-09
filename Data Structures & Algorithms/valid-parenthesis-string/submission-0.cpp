class Solution {
public:
    bool checkValidString(string s) {
        
        int low = 0;
        int high = 0;

        for(auto it : s)
        {
            if(it == '(')
            {
                low++;
                high++;
            }
            else if( it == ')')
            {
                low--;
                high--;
            }
            else
            {
                low--;
                high++;
            }

            low = max(0,low);
            if(high<0) return false;
        }

        return low == 0;
    }
};
