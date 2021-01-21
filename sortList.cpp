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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowprev = head;
        while(fast and fast->next){
            slowprev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slowprev->next = NULL;
        return slow;
        
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* mid = findMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode temp(0);
        ListNode* ptr = &temp;
        
        while(left and right){
            if(left->val <= right->val){
                ptr->next = left;
                left = left->next;
            } else{
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        
        if(left){
            ptr->next = left;
        } else{
            ptr->next = right;
        }
        
        return temp.next;
    }
};
