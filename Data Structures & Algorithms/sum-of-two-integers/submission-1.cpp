class Solution {
public:
    int getSum(int a, int b) {
        
        int sum = sum;
        int carry = 0;

        while(b)
        {
            sum = a^b;
            carry = (a&b)<<1;

            b = carry;
            a = sum;
        }

        return sum;
    }
};
