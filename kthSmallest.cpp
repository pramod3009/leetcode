class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int,int>>, std::vector<pair<int, pair<int,int>>>, std::greater<pair<int, pair<int,int>>>> q;
        int n = std::min(k, int(matrix[0].size()));
        for(int i = 0 ; i < n; i++){
            q.push({matrix[i][0],{i, 0}});
        }
        int kthsmallest = 0;
        while(k--){
            auto temp = q.top();
            q.pop();
            kthsmallest = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            if(col + 1 < matrix.size()){
                q.push({matrix[row][col + 1], {row , col + 1}});
            }
        }
        return kthsmallest;
    }
};
