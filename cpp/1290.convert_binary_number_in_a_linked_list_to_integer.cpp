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
    int recursion(ListNode* head, int& count) {
        int ans;
        if(head==nullptr) {
            return 0;
        }
        ans=recursion(head->next, count);
        if(head->val==1) {
            ans+=pow(2, count);
        }  
        count++;
        return ans;
    }
    int getDecimalValue(ListNode* head) {
        int count=0;
        return recursion(head, count);
    }
};
