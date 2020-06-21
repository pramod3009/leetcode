/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int listLength=0;
    int i=0;
    struct ListNode*temp = head;
    struct ListNode*temp2;
    for(; temp; temp=temp->next) {
       listLength+=1; 
    }
    if (listLength == n) {
      temp = head;
      head = head->next;
      free(temp);
      return head;
    }
    temp = head;
    for (i=1; i<listLength-n; i++) {
      temp = temp->next;  
    }
    temp2 = temp->next;
    temp->next= temp2->next;
    if (temp2) {
       free(temp2); 
    }
    return head;
}