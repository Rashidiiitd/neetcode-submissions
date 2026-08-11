class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid) {
        long long  totalHour = 0;
        for (auto it : piles) {
            totalHour += ((it+mid-1)/mid);
        }
        return totalHour <= h;
    }


/*

In simple words we need to find out the speed of koko so that she can eats all of the bananas within h hours.

what will be the speed ?
 because within one p she can only eat one time. so maximum speed will be the maximums number of bananas in a pile.


 lowest speed = 1;
 highest speed  = max(piles);

 one way to find the min speed that satisfy our requirement is using 
 linear search. 

 optimized way -> use binary seach to find the speed that satisfy our requirement.

 Time Complexity -> logn*(N) = NlogN. -> in optimized case.
                               N*N    -> in using linear search.

*/
int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (low <= high) { 
            int mid = (high - low) / 2 + low;

            if (isPossible(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};