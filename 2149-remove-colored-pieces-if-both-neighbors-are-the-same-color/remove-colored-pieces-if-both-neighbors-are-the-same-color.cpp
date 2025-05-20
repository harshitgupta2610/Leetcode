class Solution {
public:
    bool winnerOfGame(string s) {
        int  n= s.size();
        int a=0;
        int b=0;

        for(int i =0;i<n-2;i++){
            
            if(s[i]==s[i+1]&& s[i+1]==s[i+2]){
                if(s[i+1]=='A'){
                    a++;
                }
                else if(s[i+1]=='B'){
                    b++;
                }
            }
        }
        return a>b;
    }
};