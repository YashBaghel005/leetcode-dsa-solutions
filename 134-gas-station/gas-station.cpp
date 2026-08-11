class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int sum = 0;
        int total = 0;
        for(int i = 0; i<gas.size(); i++){
            if(sum < 0 ){
                start = i;
                sum = 0;
            }
            sum += gas[i]-cost[i];
            total+=gas[i]-cost[i];
        }
        if(total < 0){
            return -1;
        }
        return start;
    }
};