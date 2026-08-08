class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        bool isNeg = x<0?1:0;


        while(x)
        {
            int last = x%10;
            if (isNeg) {
                if(ans < INT_MIN/10 || (ans == INT_MIN/10 && last < -8)) return 0;
            } else {
                if(ans > INT_MAX/10 || (ans == INT_MAX/10 && last > 7)) return 0;

            }
            ans = ans*10 + last;
            x /= 10;
        }

        return ans;
    }
};
