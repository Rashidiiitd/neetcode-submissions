class Solution { 
public: 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { 
        int totalTank = 0; 
        int currentTank = 0; 
        int startIndex = 0; 

        for(int i = 0; i < cost.size(); i++) { 
            int fuelNet = gas[i] - cost[i];
            totalTank += fuelNet; 
            currentTank += fuelNet; 

            if(currentTank < 0) { 
                startIndex = i + 1; 
                currentTank = 0; 
            } 
        } 
        return (totalTank < 0) ? -1 : startIndex; 
    } 
};
