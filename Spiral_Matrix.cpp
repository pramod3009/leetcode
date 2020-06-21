class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;
        
        int m = matrix.size();
        if(!m)
            return result;
        int n = matrix[0].size();
        if(!n)
            return result;
        int i=0 , j=0;
        while(i<=m/2 and j<=n/2){
            
            for(int z = j; z < n-j; z++){
                result.push_back(matrix[i][z]);
            }
                        if(result.size()==m*n)
                break;
            for(int z = i+1 ; z < m-i; z++){
                result.push_back(matrix[z][n-j-1]);
            }
                        if(result.size()==m*n)
                break;
            for(int z = n-j-2; z>=j ; z--){
                result.push_back(matrix[m-i-1][z]);
            }
                        if(result.size()==m*n)
                break;
            for(int z = m-i-2; z>i;z--) {
                result.push_back(matrix[z][j]);
            }
            i++;j++;
            if(result.size()==m*n)
                break;
        }
        
        return result;
        
    }
};