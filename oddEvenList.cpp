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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next){
            return head;
        }
        ListNode* oddend = head;
        ListNode*  evenend = head->next;
        ListNode*    evenstart = head->next;
        int nodenumber = 3;
        ListNode* runner = head->next->next;
        while(runner){
            if(nodenumber % 2 == 1){
                oddend->next = runner;
                oddend = runner;
            } else {
                evenend->next = runner;
                evenend = runner;
            }
            runner = runner->next;
            nodenumber++;
        }
        evenend->next = NULL;
        oddend->next = evenstart;
        return head;
    }
};
