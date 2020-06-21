class ProductOfNumbers {
public:
   
    ProductOfNumbers() {
        sum = 1;
    }
    
    void add(int num) {
        if(num == 0){
            sum = 0;
            v.clear();
        } else if(sum==0){
            sum = num;
            v.push_back(sum);
        } else{
            sum*=num;
            v.push_back(sum);
        }
        //cout<<num<<endl;
        //printVector();
    }
    
    int getProduct(int k) {
        if(k>v.size()){
            return 0 ;
        }
        int n = v.size();
        return v[n - 1] / (n - k - 1 >= 0 ? v[n-k-1]:1);
    }
    
    vector<int> v; 
    int sum;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */