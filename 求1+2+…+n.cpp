class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1)); //n && .. �𵽿�������
        return n; 
    }
};