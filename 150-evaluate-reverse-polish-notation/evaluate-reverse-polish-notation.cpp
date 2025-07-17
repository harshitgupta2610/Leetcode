class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s :tokens){
            if(s=="+"){
                int b =st.top();
                st.pop();
                int a =st.top();
                st.pop();
                st.push(a+b);
            }
            else if(s=="-"){
                int b =st.top();
                st.pop();
                int a =st.top();
                st.pop();
                st.push(a-b);
            }
            else if(s=="*"){
                int b =st.top();
                st.pop();
                int a =st.top();
                st.pop();
                st.push(a*b);
            }
            else if(s=="/"){
                int b =st.top();
                st.pop();
                int a =st.top();
                st.pop();
                st.push(a/b);
            }else{
                int x = stoi(s);
                st.push(x);
            }
        }
        int x =st.top();
        return x;
    }
};