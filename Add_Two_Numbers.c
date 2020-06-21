/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  if(l1 == NULL)
      return l2;
    
  if(l2 == NULL)
      return l1;
    
  struct ListNode* temp1 = l1, *temp2 = l2, *head = NULL, *temp3,*node;
  int sum=0, carry=0;
  for(; temp1 && temp2; temp1=temp1->next, temp2=temp2->next) {
    sum = temp1->val + temp2->val + carry;
    carry=0;  
    if (sum>=10) {
      carry = (int)(sum/10);
      sum = sum%10;  
    }  
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = sum;
    node->next = NULL;
    if (!head) {
       head = node;
       temp3 = node; 
    } else {
      temp3->next = node;
      temp3 = node;  
    }
      
  }
  
  for(; temp1; temp1=temp1->next) {
     sum = temp1->val + carry;
     carry=0; 
    if (sum >= 10) {
      carry = (int)(sum/10);
      sum = sum%10;  
    }  
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = sum;
    node->next = NULL;
    if (!head) {
       head = node;
       temp3 = node; 
    } else {
      temp3->next = node;
      temp3 = node;  
    } 
  }
  
  for(; temp2; temp2=temp2->next) {
     sum = temp2->val + carry;
     carry=0; 
    if (sum >= 10) {
      carry = (int)(sum/10);
      sum = sum%10;  
    }  
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = sum;
    node->next = NULL;
    if (!head) {
       head = node;
       temp3 = node; 
    } else {
      temp3->next = node;
      temp3 = node;  
    } 
  }
  
  if(carry) {
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = carry;
    node->next = NULL;
    temp3->next = node;
    temp3 = node;  
  }
  return head;  
}