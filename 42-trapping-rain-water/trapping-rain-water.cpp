class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
        vector<int> lmax(n);//conatins left most
        vector<int> rmax(n);//contains right most

        lmax[0]=height[0];//intialize
        rmax[n-1]=height[n-1];//intialize

        //building leftmost array
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],height[i]);
        }

        //building rightmost array
        for(int i = n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],height[i]);
        }

        int sum =0;
        //ex-   4 0 2 here lmax = 4 rmax =2 we s=are standing at 0 min(lmax,ramx) - height
        // so - min(4,2) - height 2- 0 == 2
        for(int  i=0;i<n;i++){
            int h = min(lmax[i],rmax[i])-  height[i];
            sum+=h;
        }
        return sum;
    }
};