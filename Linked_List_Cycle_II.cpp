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
    ListNode *detectCycle(ListNode *head) {
      if(!head){
        return NULL;  
      }  
      ListNode *l1 = head;
      ListNode* l2 = head->next;
      bool flag = false;  
      while(l1 and l2 and l2->next){
        if(l1 == l2){
          flag = true;
          break;  
        }
        l1 = l1->next;
        l2 = l2->next->next;  
      }
      if(flag) {
        std::map<ListNode*,int> list;
        ListNode *temp = head;
          
        while(temp){
           if(list.find(temp)==list.end()){
             list.insert(make_pair(temp,1));  
             temp = temp->next;  
           } else {
             return temp;  
           } 
        }  
          
      }
        return NULL;  
      
        
    }
};