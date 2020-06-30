bool sortfunc( const vector<int>& v1, const vector<int>& v2 ) { 
        return v1[0] < v2[0]; 
    }
class Solution {
public:
    int result;
     
    void count(vector<bool> &col){
        bool flag1 = false, flag2 = false;
        if(not(col[2] or col[3] or col[4] or col[5])){
            flag1 = true;
            result++;
        }
        if(not(col[6] or col[7] or col[8] or col[9])){
            flag2 = true;
            result++;
        }
        if(not(flag1 or flag2)){
            if(not(col[4] or col[5] or col[6] or col[7])){
                result++;
            }
        }
    }
    void print(vector<vector<int>>& reservedSeats){
        for(auto i:reservedSeats){
            cout<<i[0]<<" "<<i[1]<<endl;
        }
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end(), sortfunc);
        print(reservedSeats);
        int prev = reservedSeats[0][0];
        vector<bool> col(11,false);
        for(auto row:reservedSeats){
            if(row[0]==prev){
                col[row[1]] = true;
                prev = row[0];
            } else {
                 count(col);
                 n--;
                std::fill(col.begin(), col.end(), false);
                col[row[1]] = true;
                prev = row[0];
            }
        }
        count(col);
        n--;
        result+=n*2;
        return result;
        
    }
};
