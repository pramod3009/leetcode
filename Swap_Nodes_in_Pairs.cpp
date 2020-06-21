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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *temp1 = head,*temp2=NULL,*temp3=NULL;
        if(temp1->next)
            temp2=temp1->next;
        while(temp1 && temp2) {
            if(temp1==head)
                head=temp2;
            temp1->next=temp2->next;
            temp2->next=temp1;
            if(temp3)
                temp3->next = temp2;
            //cout<<temp1->val<<temp2->val<<"\n";
            temp3=temp1;
            temp1=temp1->next;
            
            if(temp1 && temp1->next)
                temp2=temp1->next;
            else
                temp2=NULL;
        }
        return head;
        
    }
};