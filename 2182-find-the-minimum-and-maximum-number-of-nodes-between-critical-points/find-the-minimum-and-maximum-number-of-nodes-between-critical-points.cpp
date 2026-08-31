/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return {-1,-1};
        }
        ListNode* curr = head->next;
        ListNode* prev = head;
        int fc = 0;
        int c = 1;
        int i = 1;
        int ans1 = INT_MAX;
        int ans2 = INT_MIN;
        while(curr->next != NULL){
            if((curr->next->val > curr->val && prev->val > curr->val) || (curr->next->val < curr->val && prev->val < curr->val)){
                if(fc){
                    ans1 = min(ans1,i-c);
                    ans2 = max(ans2,i-fc);
                    c = i;
                }else{
                    fc = i; 
                    c = i;
                }
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        if(ans1 == INT_MAX || ans2 == INT_MIN){
            return {-1,-1};
        }
        return {ans1,ans2};
    }
};