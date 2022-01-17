class Solution {
public:
    int sumNums(int n) {
        //不用if如何判断递归出口，用&&
        int res=0;
        n && (res=n+sumNums(n-1));
        return res;
    }
};
