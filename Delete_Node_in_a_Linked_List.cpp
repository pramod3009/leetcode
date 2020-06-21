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
    void swap(ListNode *a, ListNode *b){
        int temp = 0;
        temp = a->val;
        a->val = b->val;
        b->val = temp;
    }
    void deleteNode(ListNode* node) {
        ListNode* lead = node;
        ListNode* trail = NULL;
        while(lead->next) {
          trail = lead;
          lead = lead->next;
          swap(trail,lead);  
        }
        trail->next = NULL;
    }
};