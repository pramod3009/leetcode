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
    ListNode* reverseList(ListNode* head) {
      ListNode *lead = head;
      ListNode *middle = NULL;
      ListNode *tail = NULL;
      
      while(lead) {
        middle = lead;
        lead = lead->next;
        middle ->next = tail;
        tail = middle;  
      }  
      return middle;  
    }
};