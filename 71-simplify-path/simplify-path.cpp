class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        stack<string> st;
        while(getline(ss,token,'/')){
            if(token==""||token=="."){
                continue;
            }
            else if(token!=".."){
                st.push(token);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        string result;
        while(!st.empty()){ 
            result="/"+st.top()+result;
            st.pop();
        }
        if(result.length()==0) 
            result="/";
        return result;
    }
};