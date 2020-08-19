class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0){
            return 0;
        }
        stack<int> stack;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i]!="+" and tokens[i]!="*" and tokens[i]!="/" and tokens[i]!="-"){
                stack.push(stoi(tokens[i]));
            } else {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                if(tokens[i] == "+"){
                    stack.push(num1 + num2);
                } else if(tokens[i] == "-"){
                    stack.push(num2 - num1);
                } else if(tokens[i] == "*"){
                    stack.push(num1 * num2);
                }else if(tokens[i] == "/"){
                    stack.push(num2 / num1);
                }
                        
                   
            }
        }
        return stack.top();
    }
    
};
