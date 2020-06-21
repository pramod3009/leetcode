/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode    *temp = NULL;
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

