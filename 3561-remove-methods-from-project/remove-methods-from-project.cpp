class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> mp_in;
        unordered_map<int,vector<int>> mp_out;
        for(int i = 0; i<invocations.size(); i++){
            int a = invocations[i][0];
            int b = invocations[i][1];
            mp_out[a].push_back(b);
            mp_in[b].push_back(a);
        }
        queue<int> q;
        vector<bool> vis(n,0);
        vector<bool> sus(n,0);
        q.push(k);
        vis[k] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            sus[t] = true;
            for(int i = 0; i<mp_out[t].size(); i++){
                int a = mp_out[t][i];
                if(!vis[a]){
                    q.push(a);
                    vis[a] = true;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(sus[i]){
                for(int j = 0; j < mp_in[i].size(); j++){
                    if(!sus[mp_in[i][j]]){
                        vector<int> ans;
                        for(int x = 0; x < n; x++)
                            ans.push_back(x);

                        return ans;
                    }
                }
            }
        }
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(!sus[i])
                ans.push_back(i);
        }

        return ans;
    }
};