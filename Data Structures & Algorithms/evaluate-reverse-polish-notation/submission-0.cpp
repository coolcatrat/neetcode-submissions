class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //check for operator, if not push into stack.
        stack<int> st;
        for(string s : tokens){
            if(s == "*" || s == "+" || s == "-" || s=="/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(s == "*") st.push(a*b);
                else if(s == "+") st.push(a+b);
                else if(s == "-") st.push(b-a);
                else if(s == "/") st.push(b/a);
            }else
                st.push(stoi(s));
        }
        return st.top();
    }
};
