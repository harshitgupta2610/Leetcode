class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(auto &ch : s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
                    vowels.push_back(ch);
                }
        }
        sort(vowels.begin(),vowels.end());
        int idx=0;
        for(auto &ch1: s){
                if(ch1=='a'||ch1=='e'||ch1=='i'||ch1=='o'||ch1=='u'||
                   ch1=='A'||ch1=='E'||ch1=='I'||ch1=='O'||ch1=='U'){
                    ch1 = vowels[idx];
                    idx++;
                }
            }
        
        return s;
    }
};