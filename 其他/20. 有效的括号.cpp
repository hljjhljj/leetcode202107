//写得不简洁但清楚
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> stack;
        for(char c:s){
            //左括号全部压栈
            if(c=='(' || c=='[' || c=='{') stack.push(c);
            //接下来要pop，防止栈为空，也就是输入为']'这种情况
            else if(stack.empty()) return false;
            else if(c==')')
                if(stack.top()=='(') stack.pop();
                else return false;
            else if(c==']')
                if(stack.top()=='[') stack.pop();
                else return false;
            else if(c=='}')
                if(stack.top()=='{') stack.pop();
                else return false;
        }
        return stack.empty();
    }
};
