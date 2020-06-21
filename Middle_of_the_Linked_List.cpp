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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* l = head;
        while(l){
            len++;
            l = l->next;
        }
        l = head;
        for(int i=1; i < (len/2)+1 ; i++) {
            l = l->next;
        }
        return l;    
    }
};