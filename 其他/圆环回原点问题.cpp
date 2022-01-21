//https://mp.weixin.qq.com/s/NZPaFsFrTybO3K3s7p7EVg
int main() {
    int t=2,n=10;
    vector<vector<int>> dp(t+1,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=1;i<=t;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=dp[i-1][(j+1+n)%n]+dp[i-1][(j-1+n)%n];
        }
    }
    cout<< dp[t][0] << endl;
}
