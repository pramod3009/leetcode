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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t1 = NULL;
        ListNode* t2 = head;
        ListNode* lastUnique = NULL;
        while(t2){
            if(t1 and t1->val == t2->val){
                while(t2 and t1->val == t2->val){
                    t2 = t2->next;
                }
                t1 = t2;
                t2 = t2?t2->next:t2;
                if(lastUnique){
                    lastUnique->next = t1;
                } else {
                  head = t1;  
                }
                
            } else {
                lastUnique = t1;
                t1 = t2;
                t2 = t1->next;
            }
        }
        return head;
    }
};
