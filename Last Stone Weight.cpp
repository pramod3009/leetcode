class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(not stones.size()){
            return -1;
        }
        priority_queue<int> q;
        for(auto num:stones){
            q.push(num);
        }
        while(q.size()!=1 and !q.empty()){
            int num1 = q.top();
            q.pop();
            int num2 = q.top();
            q.pop();
            if(num1!=num2){
                q.push(num1 - num2);
            }
        }
        return q.size()?q.top():0;
    }
};