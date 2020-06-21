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
    ListNode* removeZeroSumSublists(ListNode* head) {
    vector<int> array;
    while(head){
        array.push_back(head->val);
        head=head->next;
    }
    int i =0;  
        
    while(i<array.size()){
        int sum = array[i];
        if(sum==0){
            array.erase(array.begin()+i, array.begin()+i+1);
            continue;
        }
        int j = i+1;
        while(j<array.size()){
            sum = sum+array[j];
            if (sum==0){
              array.erase(array.begin()+i, array.begin()+j+1);
                i--;
                break;
            }
            j++;
        }
        i++;
    }
         ListNode* result = nullptr;
        ListNode* temp = nullptr;

        for (int i = array.size()-1; i >= 0; i--) {
            result = new ListNode(array[i]);
            result->next = temp;
            temp = result;
        }

        return result;
     
}
};