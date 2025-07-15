class Solution {
public:
    bool isValid(string word) {

        int n = word.length();
        if(n<3){
            return false;
        }
        bool hasVowel = false;
        bool hasConsonant = false;
        
        for(char ch : word){
            if(isalpha(ch)){
                char ch1 = tolower(ch);
                if(ch1 == 'a' ||ch1 == 'e' ||ch1 == 'i' ||ch1 == 'o' ||ch1 == 'u'){
                    hasVowel = true;
                }else{
                    hasConsonant = true;
                }
            }else if(!isdigit(ch)){
                return false;
            }

        }
        return hasVowel && hasConsonant;
    }
};