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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !(head->next))
            return head;
        int len = 0;
        
        ListNode* l1 = head;
        while(l1){
            len++;
            l1 = l1->next;
        }
        k = k%len;
        l1 = head;
        for(int i=0;i<len-k-1;i++){
          l1=l1->next;
        }
        ListNode* temp = l1->next;
        if(!temp)
            return head;
        while(temp->next){
            temp = temp->next;
            
        }
        temp->next = head;
        head = l1->next;
        l1->next = NULL;
        return head;
    }
};