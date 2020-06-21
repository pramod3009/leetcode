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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> list;
        if(!head || !(head->next)){
            list.push_back(0);
            return list;
        }
            
        ListNode* trail = head;
        ListNode* lead = NULL;
        while(trail->next){
           int max = trail->val; 
            lead= trail->next;
           while(lead){
              if(max < lead->val) {
                  max = lead->val;
                  break;
              }
              lead = lead->next; 
           }
           if(!(max > trail->val)){
               max = 0;
           } 
           list.push_back(max);
           trail = trail->next; 
        }
        list.push_back(0);
        return list;
    }
};