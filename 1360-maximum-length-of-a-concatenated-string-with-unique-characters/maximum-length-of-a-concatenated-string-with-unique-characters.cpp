class Solution {
public:
    unordered_map<string ,int> mp;
    bool hasDup(string &s1, string &s2){
        int arr[26]={0};
        for(char &ch  : s1){
            if( arr[ch-'a']>0){
                return true;
            }
            arr[ch-'a']++;
        }
        for( char &ch : s2 ){
            if(arr[ch-'a']>0){
                return true;
            }
        }
        return false;
    }
    int helper(int idx, string temp,vector<string>& arr,int n){
        if(idx>=n){
            return temp.length();
        }
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        int take = 0; 
        int skip =0;

        if(hasDup(arr[idx],temp)){
            skip= helper(idx+1,temp,arr,n);
        }
        else{
            skip= helper(idx+1,temp,arr,n);
            take= helper(idx+1,temp + arr[idx],arr,n);
           

        }
        return mp[temp]=max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        mp.clear();
        int n = arr.size();
        int idx=0;
        return helper(idx,temp,arr,n);
    }
};