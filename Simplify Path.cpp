#include<cstring>
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int i = 0;
        string temp = "";
        path += "/";
        while(i < path.size()){
            
            if(path[i]=='/'){
                if(!temp.empty()){
                    if(temp == "."){

                    } else if(temp == ".."){
                        if(!stk.empty()){
                            stk.pop();
                        }
                    } else {
                        stk.push(temp);
                    }
                }
              temp.clear();  
            } else{
                temp+=path[i];
            }
            
            i++;
        }
        string ans= "";
        while(!stk.empty()){
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        if(ans.size()==0){
            ans +="/"; 
        }
        return ans;
    }
};
