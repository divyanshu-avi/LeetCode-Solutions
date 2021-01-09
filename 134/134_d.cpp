class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i, n = gas.size(), sum=0, tank=0, start = 0;
        for(i=0;i<n;i++)
        {
            tank += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(tank<0)
            {
                /*Reason behind this is that if some station X can't reach a station Y then, 
                the station b/w X and Y also can't reach Y.
                Think about it and convince yourself that it is true.*/
                start = i+1;
                tank = 0;
            }
        }
        //If sum>=0 then there always exists a solution
        return sum >= 0 ? start : -1;
        /*start represents a position from where if we travel to end, tank will be >=0.
        But, we want to travel back to start and not just to the end!(in a complete circle)
        But, if sum is >=0 we are guaranteed that tank(start to end) >= tank(end to start).
        Hence, we can always complete the circle without even checking for end to start!/*
    }
};