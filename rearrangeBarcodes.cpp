class Solution {
public:
    priority_queue<pair<int,int>, vector<pair<int,int>>> q;
    map<int,int> m;
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        //q.clear();
        m.clear();
        if(barcodes.size()<=1){
            return barcodes;
        }
        for(auto bar : barcodes){
                m[bar]++;
        }
        for(auto it : m){
            q.push({it.second, it.first});
        }
        vector<int> result;
        while(!q.empty()){
            auto f = q.top();
            q.pop();
            
            result.push_back(f.second);
            if(!q.empty()){
                auto s = q.top();
                q.pop();
                result.push_back(s.second); 
                if(--s.first > 0){
                    q.push(s);
                 }
            }
            if(--f.first > 0){
                q.push(f);
            }
            
        }
            
        return result;
    }
};
