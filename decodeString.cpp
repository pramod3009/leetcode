class Solution {
public:
    string decodeString(string st) {
        stack<char> s;
        string res = "";
        string last = "";
        int n = st.length() - 1;
        while(n>=0 and st[n]!=']'){
            n--;
        }
        for(int i = 0;i<=n;i++){
            auto c= st[i];
            if(c==']'){
                string temp="";
                while(!s.empty() and s.top()!='['){
                    temp = s.top() + temp;
                    s.pop();
                }
                s.pop();
                string num="";
                while(!s.empty() and s.top()>='0' and s.top()<='9'){
                    num = s.top() + num;
                    s.pop();
                }
                int n = stoi(num);
                cout<<temp<<" "<<num<<" "<<n<<endl;
                string repeated="";
                for(int i = 0;i < n ; i++){
                    repeated = repeated + temp;
                }
                for(auto r : repeated){
                   s.push(r); 
                }
                
            } else {
                s.push(c);
            }
        }
        while(!s.empty()){
            res =  s.top() + res  ;
            s.pop();
        }    
            
        return res + st.substr(n + 1, st.size() - n - 1);
    }
};
