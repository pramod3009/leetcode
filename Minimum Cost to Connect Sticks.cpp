class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int result = 0;
        if(sticks.size() ==0 or sticks.size()==1){
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto stick : sticks){
            q.push(stick);
        }
        
        while(q.size() > 1){
            int stick1 = q.top();
            q.pop();
            int stick2 = q.top();
            q.pop();
            //cout<<result<<" "<<stick1<<" "<<stick2<<endl;
            result += stick1 + stick2;
            q.push(stick1 + stick2);
        }
        return result;
    }
};
