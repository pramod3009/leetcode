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
    void reverse(ListNode* headm, ListNode *headn,int k){
        ListNode* trail = NULL;
        ListNode* middle = NULL;
        ListNode* lead = headm;
        while(lead and k>=0){
            middle = lead;
            lead = lead->next;
            middle->next = trail;
            trail = middle;
            k--;
        }
        
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* headm = NULL;
        ListNode* headn = NULL;
        ListNode* prev = NULL;
        ListNode* temp = head;
        int i = 1;
        while(temp){
            if(i==m-1){
                prev = temp; 
            }
            if(i==m){
                headm = temp;
            }
            if(i==n){
                headn = temp;
                break;
            }
            temp = temp->next;
            i++;
        }
        ListNode* nextnode = headn->next;
        reverse(headm, headn,n-m);
        if(prev){
             prev->next = headn;
        }
        headm->next = nextnode;
        if(headm == head){
            head = headn;
        }
        return head;
    }
};