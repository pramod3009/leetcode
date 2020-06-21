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
void reverseList(ListNode* head) {
      
      ListNode *lead = head;
      ListNode *middle = NULL;
      ListNode *tail = NULL;
      
      while(lead) {
        middle = lead;
        lead = lead->next;
        middle ->next = tail;
        tail = middle;  
      }  
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !(head->next)){
          return head;
      }
        ListNode* trail = head;
        ListNode* lead = head;
        int count;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        
        while(lead){
           int count = k-1;
           while(count){
             if(lead){
                 lead = lead->next;
             }else {
                 //cout<<prev->val<<" "<<trail->val;
                 if(prev){
                    prev->next = trail;
                 }    
                 return head;
             }
             count--;  
            }
            if(lead){
              temp = lead->next;
              lead->next = NULL;
            } else {
              return head;  
            }    
            reverseList(trail);
            if(trail==head){
                head = lead;
            }
            if(!prev){
                prev = trail;
            } else {
                prev->next = lead;
                prev = trail;
            }
            trail->next = temp;
            //cout<<" "<<trail->val<<" "<<temp->val<<endl;
            lead = temp;
            trail = temp;
            
        }
        prev->next = trail;
        return head;
    }
};