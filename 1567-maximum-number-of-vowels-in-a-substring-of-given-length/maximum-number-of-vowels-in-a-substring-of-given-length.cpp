class Solution {
public:
    bool check(char &ch){
        return ch =='a'||ch =='e'||ch =='i'||ch =='o'||ch =='u';
    }
    int maxVowels(string s, int k) {
       int n = s.length();
       int i =0,j=0;
       int maxV=0;
       int count=0 ;

       while(j<n){
            if(check(s[j])){
                count++;
            }

            if(j-i+1==k){
                maxV=max(maxV,count);
                if(check(s[i])){
                    count--;
                }
                i++;
            }
            j++;
       }
       return maxV;
    }
};