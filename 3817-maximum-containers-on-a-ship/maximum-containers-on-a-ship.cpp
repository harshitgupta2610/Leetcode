class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int maxn=n*n;
        int currweight = maxn*w;
        if(currweight>maxWeight){
            maxn=maxWeight/w;
        }
        return maxn;
    }
};