/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(not head){
            return head;
        }
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode* third = head;
        ListNode* startSecond = NULL; 
        while(third){
            if(third->val < x){
                if(!first){
                    first = third;
                    third = third->next;
                    first->next = startSecond;
                    head = first;
                    
                } else{
                    ListNode* temp = third->next;
                    third->next = first->next;
                    first->next = third;
                    first = third;
                    third = temp;
                }
                
                
            } else{
                if(!second){
                    startSecond = third;
                    second = third;
                    if(first){
                        first->next = startSecond;
                    }
                    
                } else{
                    second->next = third;
                    second = third;
                }
                
                third = third->next;
                
            }
        }
        if(second){
          second->next = NULL;  
        }
        
        return head;
    }
};
