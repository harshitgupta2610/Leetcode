class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i =0;
        int j =n-1;
        int ares =0;
        int h =0;
        int maxarea = INT_MIN;
        while(i<j){
            int width = j-i;
            int h = min(height[i],height[j]);
            int area = width * h;
            maxarea = max(maxarea,area);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxarea;
    }
};