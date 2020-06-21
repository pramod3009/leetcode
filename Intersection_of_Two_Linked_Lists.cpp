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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        int lenA=0,lenB=0;
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1) {
          lenA++;
          l1 = l1->next;  
        }
        while(l2) {
          lenB++;
          l2 = l2->next;  
        }
        l1 = headA;
        l2 = headB;
        if (lenA > lenB){
            for(int i=0; i<lenA-lenB; i++) {
                l1 = l1->next; 
            }
        } else if (lenB > lenA) {
            for(int i=0; i<lenB-lenA; i++) {
               l2 = l2->next; 
            }
        }
        for(; l1 && l2; l1 = l1->next, l2 = l2->next) {
            if (l1 == l2)
                return l1;
        }
        return NULL;
    }
};