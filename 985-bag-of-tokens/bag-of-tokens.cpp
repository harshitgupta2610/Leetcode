class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int maxs=0;
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i =0;
        int j =n-1;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                maxs = max(maxs,score); 
                power -= tokens[i]; 
                i++;
            }
            else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                return maxs;
            }
        }
        return maxs;
    }
};