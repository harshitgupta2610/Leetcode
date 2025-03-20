class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length()>n){
            return "";
        }
        unordered_map<char ,int> mp;
        for(auto &ch: t){
            mp[ch]++;
        }
        int count = t.size();
        int i =0;
        int j =0;
        int mini=0;
        int minwin = INT_MAX;
        while(j<n){
            char chj=s[j];
            if(mp[chj]>0){
                count--;
            }
            mp[chj]--;
            while(count==0){
                if(minwin>j-i+1){
                    minwin= j-i+1;
                    mini=i;
                }
                char chi = s[i];
                mp[chi]++;
                if(mp[chi]>0){
                    count++;
                }
                i++;
            }
            j++;
        }
        if(minwin==INT_MAX){
            return "";
        }
        string s1 = s.substr(mini,minwin);
        return s1;
    }
};