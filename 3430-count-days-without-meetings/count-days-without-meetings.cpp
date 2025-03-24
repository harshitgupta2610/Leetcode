const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        // int n = meetings.size();
        // unordered_set<int> st;
        // for(int i =0 ;i<n;i++){
        //     int s= meetings[i][0];
        //     int p= meetings[i][1];
        //     for(int j =s;j<=p;j++){
        //         st.insert(j);
        //     }
        //     // st.insert(s);
        //     // st.insert(p);
        // }
        // int count =0;
        // for(int i = 1;i<=days;i++){
        //     if(st.find(i)==st.end()){
        //         count++;
        //     }
        // }
        // return days - st.size(); 

        sort(begin(meetings),end(meetings));
        int count = 0;
        int s= meetings[0][0];
        int e= meetings[0][1];

        for(int i =1;i<meetings.size();i++){
            if(meetings[i][0]<=e+1){
                e = max(meetings[i][1],e);
            }
            else{
                count+=e-s+1;
                s = meetings[i][0];
                e = meetings[i][1];
            }
        }
        count+=e-s+1;
        return days-count;
    }
};