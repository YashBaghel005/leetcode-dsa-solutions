/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>> &mp){
        if(root == NULL){
            return;
        }
        if(root->left){
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
        }
        if(root->right){
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
        }

        solve(root->left,mp);
        solve(root->right,mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,vector<TreeNode*>> mp;
        solve(root,mp);
        unordered_map<TreeNode*,int> dis;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        dis[target] = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int d = t.second;
            TreeNode* node = t.first;
            for(int i = 0; i<mp[node].size(); i++){
                if(dis.find(mp[node][i]) == dis.end()){
                    dis[mp[node][i]] = d+1;
                    q.push({mp[node][i],d+1});
                }
            }
        }
        vector<int> ans;
        for(auto &[key,value]:dis){
            if(value == k){
                ans.push_back(key->val);
            }
        }
        return ans;
    }
};