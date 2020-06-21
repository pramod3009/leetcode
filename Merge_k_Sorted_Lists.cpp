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
  ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
    ListNode *head = NULL;
    ListNode    *temp = NULL;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
           if(!head) {
             head = temp = l1;  
           } else {
             temp->next = l1;
             temp = l1;  
           }
            l1=l1->next;
        } else {
          if(!head) {
            head = temp = l2;  
          } else {
            temp->next = l2;
            temp = l2;  
          }
          l2=l2->next;  
        }
    }
    while(l1){
           if(!head) {
             head = temp = l1;  
           } else {
             temp->next = l1;
             temp = l1;  
           }
            l1=l1->next;        
    }
    
    while(l2) {
          if(!head) {
            head = temp = l2;  
          } else {
            temp->next = l2;
            temp = l2;  
          }
          l2=l2->next;        
    }
    return head;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<ListNode*>::iterator it;
        ListNode* head = NULL;
        for(it=lists.begin();it!=lists.end();it++){
           if(!head){
             head = *it;  
           } else {
             head = mergeTwoLists(head,*it);  
           } 
        }
        return head;
    }
};