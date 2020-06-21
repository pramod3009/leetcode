class Solution {
public:
    int minDistance(string word1, string word2) {
        int steps[word1.length()+1][word2.length()+1];
        for(int i=0;i<=word1.length();i++){
            steps[i][0]=i;
        }
        for(int j=0;j<=word2.length();j++){
            steps[0][j] = j;
        }
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                if(word1[i-1]==word2[j-1]){
                    steps[i][j] = steps[i-1][j-1];
                } else{
                    steps[i][j] = 1+min(steps[i-1][j],steps[i][j-1]);
                }
                
            }
        }
       return steps[word1.length()][word2.length()]; 
    }
};