/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        vector<pair<int,int>>events;
        int maxRoom = 0;
        for(auto it : intervals)
        
          {
            int start = it.start;
            int end = it.end;
            events.push_back({start,+1});
            events.push_back({end,-1});

          }

          sort(events.begin(),events.end());
        int ans = 0;
          for(auto event : events)
          {
            int time = event.first;
            int delta = event.second;

            if(delta>0)
            {
                ans++;
                
            }
            else
            {
                
                maxRoom = max(ans,maxRoom);
                ans--;
            }
          }
          
         maxRoom = max(ans,maxRoom);

         return maxRoom;
    }
};
