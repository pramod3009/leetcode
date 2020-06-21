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
    bool isPalindrome(ListNode* head) {
        if(!head || !(head->next))
            return true;
        std::vector<int>vec;
        ListNode *l1 = head;
        int len = 0;
        while(l1){
            vec.push_back(l1->val);
            l1 = l1->next;
            len++;
        }

        for(int i=0;i<(len/2);i++){
            if(vec[i]!=vec[len-1-i])
                return false;
        }
        return true;
        
    }
};