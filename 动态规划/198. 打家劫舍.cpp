class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        vector<int> dp(len,0);
        if(len==0) return 0;
        else if(len==1) return nums[0];
        else if(len==2) return max(nums[0],nums[1]);
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<len;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[len-1];
    }
};
