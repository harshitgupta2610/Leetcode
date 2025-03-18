class Solution {
public:
    bool helper(vector<int> &counter){
        for(int &i : counter){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string pat) {
        int n = s.size();
        int m = pat.size();
        vector<int> res;
        vector<int> counter(26,0);
       for(char &ch : pat) {
	        counter[ch-'a']++;
	    }

        int i =0;
        int j=0;
        
        while(j<n){
            counter[s[j]-'a']--;
            if(j-i+1==m){
                if(helper(counter)){
                    res.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};