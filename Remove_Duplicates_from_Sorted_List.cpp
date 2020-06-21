/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !(head->next))
            return head;
        ListNode *lead = head->next;
        ListNode *trail = head;
        ListNode *temp = NULL; 
        while(lead){
            if(trail->val != lead->val) {
                trail->next = lead;
                trail = lead;
            }
            if(!(lead->next))
                temp = lead;
            lead = lead->next;

        }
        if(trail->val == temp->val) {
                trail->next = NULL;
        }    
        return head;
    }
};