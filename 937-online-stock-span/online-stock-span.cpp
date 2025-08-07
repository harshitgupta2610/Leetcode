class StockSpanner {
public:
    vector<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        st.push_back(price);
        int n = st.size();
        int count =0;
        for(int j=n-1;j>=0;j--){
            if(st[j]<=price){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */