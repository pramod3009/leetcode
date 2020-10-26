/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void make_connection(Node *start, Node* end){
        start->next = end;
        if(end){
            end->prev = start;
        }
    }
    Node* helper(Node* head){
        Node *temp = NULL;
        while(head){
            if(head->child){
                Node *end = helper(head->child);
                Node* next = head->next;
                make_connection(end, next);
                make_connection(head, head->child);
                head->child = NULL;
            }
            temp = head;
            head = head->next;
        }
        return temp;
    }
    Node* flatten(Node* head) {
        
        helper(head);
        return head;
    }
};
