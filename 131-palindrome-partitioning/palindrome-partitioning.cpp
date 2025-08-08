class Solution {
public:
    int  n;
    bool isPal(string &s,int st,int e){
        while(st<e){
            if(s[st]!=s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
    void back(string &s,int idx, vector <string> &curr,vector<vector<string>> &result){
        
        if(idx==n){
            result.push_back(curr);
            return;
        }

        for(int i = idx;i<n;i++){
            if(isPal(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                back(s,i+1,curr,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       n = s.length();
       vector<vector<string>> result;
       vector <string> curr; 
       back(s,0,curr,result);
       return result;
    }
};