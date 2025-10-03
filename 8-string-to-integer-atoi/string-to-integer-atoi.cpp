class Solution {
public:
  int myAtoi(string s) {
    stringstream stream(s);
    int num;
    stream >> num;
    return num;
  }
};