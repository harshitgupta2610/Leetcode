class Solution {
public:
    bool isPal(int x) {
        string str = to_string(x);
        int len = str.length();
        if (len % 2 != 0) return false; 
        int half=len/2;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < half; i++) {
            sum1+=str[i]-'0';
        }
        for (int i = half;i<len;i++) {
            sum2+=str[i]-'0';
        }

        return sum1==sum2;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (isPal(i)) {
                count++;
            }
        }
        return count;
    }
};
