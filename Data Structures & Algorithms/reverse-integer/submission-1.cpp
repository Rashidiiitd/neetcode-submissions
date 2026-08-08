class Solution {
public:
    int reverse(int x) {
        int temp =x;
        int newNumber =0;
        while(temp){
        // int rem  = temp%10;
           if(newNumber<INT_MIN/10 || newNumber>INT_MAX/10){
                 return 0;
             }
             newNumber = newNumber*10 + temp%10;
             
         temp = temp/10;
        }
        
         
        return newNumber;
    }
};