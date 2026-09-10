/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int &n){
        if(root == NULL){
            return 0;
        }
        n++;
        return root->val+solve(root->right,n)+solve(root->left,n);
    }
    void solve1(TreeNode* root,int &count){
        if(root == NULL){
            return;
        }
        int n = 0;
        int sum = solve(root,n);
        if(sum/n == root->val){
            count++;
        }
        solve1(root->left,count);
        solve1(root->right,count);
    }
    int averageOfSubtree(TreeNode* root) {
        int count  = 0;
        solve1(root,count);
        return count;
    }
};