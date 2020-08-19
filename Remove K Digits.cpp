class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k){
            return "0";
        }
        stack<char> stack;
        for(int i = 0; i < num.length(); i++){
            char ch = num[i];
            while(!stack.empty() and ch < stack.top() and k > 0){
                stack.pop();
                k--;
            }
            if(stack.empty() and ch=='0'){
                continue;
            }
            stack.push(ch);
            
        }
        
        while(k > 0 and !stack.empty()){
            stack.pop();
            k--;
        }
        
        string ans;
        while(!stack.empty()){
            ans = stack.top() + ans;
            stack.pop();
        }
         if(ans.length()==0){
             return "0";
         }
        
        return ans;
    }
};
