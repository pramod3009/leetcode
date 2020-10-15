class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int>m;
        for(const auto task : tasks){
            m[task]++;
        }
        priority_queue<int> pq;
        for(const auto temp:m){
            pq.push(temp.second);
        }
        int cycles = 0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i = 0; i <=n; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                pq.pop();
                }
                
            }
            for(auto num : temp){
                if(--num){
                    pq.push(num);
                }
            }
            cycles += pq.empty() ? temp.size() : n + 1;
        }
        return cycles;
    }
};
