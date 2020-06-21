/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node*,Node*> m;
        Node* temp = head, *temp2 = NULL;
        Node* chead = NULL;
        
        while(temp){
            Node *temp1 = new Node(temp->val,NULL,NULL);
            if(!chead){
                chead = temp1;
            }
            if(!temp2){
                temp2=temp1;
            } else {
                temp2->next= temp1;
                temp2=temp1;
            }
            m[temp] = temp1;
          temp = temp->next;  
        }
        
       temp = head;
       while(temp){
         Node *temp1 = m[temp];
         temp1->random = m[temp->random];
         temp=temp->next;  
       }
     return chead;   
    }
};