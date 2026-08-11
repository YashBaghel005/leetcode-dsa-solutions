class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            freq store 
            checking 
            freq execution 
        */
        int time = 1;
        unordered_map<char,int> mp;
        unordered_map<char,int> next;
        for(int i = 0; i<tasks.size(); i++){
            mp[tasks[i]]++;
            next[tasks[i]] = 1;
        }

        while(!mp.empty()){
            char task = '#';
            int freq = 0;

            //check one available task 
            for(auto &[key, value] : mp){
                if(next[key] <= time && value > freq){
                    task = key;
                    freq = value;
                }
            }

            //  if no task foundd
            if(task == '#'){
                time++;
                continue;
            }

            // executed the selected task 
            mp[task]--;
            next[task] += (n+1);
            time++;

            if(mp[task] == 0){
                mp.erase(task);
                next.erase(task);
            } 
        }
        return time-1;
    }
};