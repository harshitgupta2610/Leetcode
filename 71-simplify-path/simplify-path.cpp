class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;
        while(getline(ss,token,'/')){
            if(token==""||token=="."){
                continue;
            }
            else if(token!=".."){
                st.push_back(token);
            }
            else if(!st.empty()){
                st.pop_back();
            }
        }
        string result;
        for(auto &token : st) {
            result += "/" + token;
        }
        if(result.length()==0) 
            result="/";
        return result;
    }
};