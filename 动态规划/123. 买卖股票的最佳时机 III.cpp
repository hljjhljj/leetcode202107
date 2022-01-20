class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days=prices.size();
        int dp[days][2+1][2];//[前i天][目前还可进行k次交易][1持有，0不持有]
        for(int i=0;i<days;i++){
            dp[i][0][1]=INT_MIN;//禁止交易时不能持有股票
            dp[i][0][0]=0;
            for(int k=1;k<=2;k++){//k=0的情况上面已经处理过了
                if(i==0){//现在处理i=0的情况
                    dp[0][k][1]=-prices[0];//dp[0][k][1]=INT_MIN就不行
                    //dp[0][k][1]=max(dp[-1][k-1][0]-prices[0],dp[-1][k][1])
                    //dp[0][k][1]=max(0-prices[0],INT_MIN)=-prices[0]
                    dp[0][k][0]=0;
                }
                else{
                    dp[i][k][1]=max(dp[i-1][k-1][0]-prices[i],dp[i-1][k][1]);
                    dp[i][k][0]=max(dp[i-1][k][1]+prices[i],dp[i-1][k][0]);
                }
            }
        }
        return dp[days-1][2][0];
    }
};
