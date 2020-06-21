class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int nf) {
        int count = 0;
        int n = flowerbed.size();
        if(n==1){
            if(flowerbed[0]==0)
                count+=1;
            return count >= nf;
        }
        //cout<<flowerbed[0]<<" "<<flowerbed[1];
        if(flowerbed[0]==0 and flowerbed[1]==0){
            flowerbed[0] = 1;
            count++;
        }
        //cout<<count;
        if(flowerbed[n-1]==0 and flowerbed[n-2]==0){
            flowerbed[n-1] = 1;
            count++;
        }
        for(int i = 1;i < n-1 ; i++){
            
            if (flowerbed[i]==0 and i-1>=0 and i+1<n and  flowerbed[i-1]==0 and                                flowerbed[i+1]==0){
                flowerbed[i] = 1;
                count+=1;
            }
        }
      return count >= nf;  
    }
};