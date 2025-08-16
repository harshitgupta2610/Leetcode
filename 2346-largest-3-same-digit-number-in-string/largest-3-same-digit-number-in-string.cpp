class Solution {
public:
    string largestGoodInteger(string num) {
        int n =num.size();
        int max1 = INT_MIN;
        for(int i =0;i<n-2;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                string s = num.substr(i,3);
                int max0 = stoi(s);
                max1 = max(max1,max0);
            }
        }
        if(max1==0){
            return "000";
        }
        if(max1==INT_MIN){
            return "";
        }
        return to_string(max1);
    }
};