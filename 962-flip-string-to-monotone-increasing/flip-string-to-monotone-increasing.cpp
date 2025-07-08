class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1 =0;
        int flip =0;
        for(char ch : s){
            if(ch=='1'){
                count1++;
            }
            else{
                flip = min(flip+1,count1);
            }
        }
        return flip;
    }
};