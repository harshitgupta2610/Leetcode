class Solution {
public:
    vector<int> res;
    
    void f(int num, int& n) {
        if(num > n)
            return;
        
        res.push_back(num);

        for(int i = 0; i <= 9; ++i) 
            f(num * 10 + i, n);
    }
    
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; ++i)
            f(i, n);
        
        return res;
    }
};