class Solution {
public:
    int matches =0;
    long long teams =0;
    long long solve(int n){
        if(n==1){
            return 0;
        }
        if(n%2!=0){
            matches += (n-1)/2;
            teams = (n-1)/2 + 1;
            solve(teams);
        }
        else{
            matches += n/2;
            teams = n/2;
            solve(teams);
        }
        return matches;
    }
    int numberOfMatches(int n) {

        return solve(n);
    }
};