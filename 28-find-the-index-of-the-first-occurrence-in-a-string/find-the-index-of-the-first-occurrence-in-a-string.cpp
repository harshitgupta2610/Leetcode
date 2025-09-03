class Solution {
public:
    int strStr(string str1, string str2) {
        int m  = str1.size();
        int n = str2.size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(str1[i+j]!=str2[j]){
                    break;
                }
                else{
                    if(j==n-1){
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};