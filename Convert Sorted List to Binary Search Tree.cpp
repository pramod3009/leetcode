/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev){
            prev->next = NULL;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* mid = findMid(head);
        TreeNode* node = new TreeNode(mid->val);
        if(mid==head){
            return node;
        }
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);
        return node;
    }
};