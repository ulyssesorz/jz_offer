class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1)); //n && .. 起到开关作用
        return n; 
    }
};