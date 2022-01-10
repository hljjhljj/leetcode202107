class Solution {
public:
    int translateNum(int num) {
        string s=to_string(num);
        int len=s.size();
        vector<int> dp(len+1,0);
        dp[0]=1;dp[1]=1;
        for(int i=2;i<=len;i++){
            if((s.at(i-2)=='1') || (s.at(i-2)=='2' && s.at(i-1)<='5')){
                dp[i]=dp[i-1]+dp[i-2];
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[len];
    }
};
