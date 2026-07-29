class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int sum = 0;
        int start = 0;
        for(int i = 0; i<gas.size(); i++){
            total_gas += gas[i]-cost[i];
            sum += gas[i]-cost[i];
            if(sum<0){
                start = i+1;
                sum = 0;
            }
        }
        if(total_gas < 0){
            return -1;
        }
        return start;
    }
};