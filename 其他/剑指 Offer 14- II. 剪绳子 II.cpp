class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int mod=1000000007;
        int a=n/3,b=n%3;
        long res=1;
        for(int i=1;i<a;i++){
            res=res*3%mod;
        }
        if(b==0) return res*3%mod;
        if(b==1) return res*4%mod;
        else return res*3*2%mod;//b=2
    }
};
