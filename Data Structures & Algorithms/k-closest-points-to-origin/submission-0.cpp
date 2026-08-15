class Solution {
public:
int calculateEucdist(int x, int y)
{
    
     // code for the formula root((x1-x2)^2 + (y1-y2)^2)
     return x*x+y*y;
} 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n = points.size(); 

        priority_queue<pair<int, vector<int>>> pq; // max 

        for(auto& point : points)
        {
            int x = point[0];
            int y = point[1];

            int dist = calculateEucdist(x,y);

            pq.push({dist,point});
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};