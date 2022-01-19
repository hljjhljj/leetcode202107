//和435. 无重叠区间的dp做法一致，但那个会超时
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int res=1,len=envelopes.size();
        vector<int> dp(len,1);
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                    res=max(res,dp[i]);
                }
            }
        }
        return res;
    }
};
