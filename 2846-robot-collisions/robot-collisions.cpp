class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // (position, health, direction, original index)
        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        // Step 1: Sort by position
        sort(robots.begin(), robots.end());

        stack<int> st; // stores indices of robots (only 'R')
        vector<bool> alive(n, true);

        // Step 2: Traverse
        for(int i = 0; i < n; i++) {
            auto& [pos, h, dir, idx] = robots[i];

            if(dir == 'R') {
                st.push(i);
            } 
            else { // dir == 'L'
                while(!st.empty() && h > 0) {
                    int j = st.top();
                    auto& [pos2, h2, dir2, idx2] = robots[j];

                    if(h2 == h) {
                        alive[j] = false;
                        alive[i] = false;
                        st.pop();
                        h = 0;
                        break;
                    }
                    else if(h2 > h) {
                        alive[i] = false;
                        h2--;
                        h = 0;
                        break;
                    }
                    else {
                        alive[j] = false;
                        st.pop();
                        h--;
                    }
                }
            }
        }

        // Step 3: Collect survivors
        vector<pair<int,int>> res;
        for(int i = 0; i < n; i++) {
            if(alive[i]) {
                auto& [pos, h, dir, idx] = robots[i];
                res.push_back({idx, h});
            }
        }

        // Step 4: Sort by original index
        sort(res.begin(), res.end());

        vector<int> ans;
        for(auto& p : res) ans.push_back(p.second);

        return ans;
    }
};