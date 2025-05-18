// class Solution {
// public:
//     string predictPartyVictory(string s) {
//         int n = s.size();
//         int countr =0;
//         int countd =0;
//         if(s=="DR"){
//             return "Dire";
//         }
//         for(int i =0;i<n;i++){
//             if(s[i]=='R'){
//                 countr+=1;
//             }
//         }
//         countd = n-countr;
//         if(countr<countd){
//             return "Dire";
//         }
//         return "Radiant";
//     }
// };
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> queR;
        queue<int> queD;
        for(int i = 0; i<n; i++) {
            if(senate[i] == 'R')
                queR.push(i);
            else
                queD.push(i);
        }
        while(!queR.empty() && !queD.empty()) {
            int R_idx = queR.front(); queR.pop();
            int D_idx = queD.front(); queD.pop();
            if(R_idx < D_idx) {
                queR.push(R_idx+n);
            } else {
                queD.push(D_idx+n);
            }
        }
        return queR.empty() ? "Dire" : "Radiant";
    }
};
