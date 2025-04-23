class Solution {
public:
    int sumi(int num){
        int sum =0 ;
        while(num){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;

        int maxS=0;
        int count =0;

        for(int i =1;i<=n;i++){
            int sumd= sumi(i);
            mp[sumd]++;
        

        if(mp[sumd]==maxS){
            count++;
        }else if(maxS<mp[sumd]){
            
            maxS=mp[sumd];
            count=1;
        }
        }
        return count;
    }
};