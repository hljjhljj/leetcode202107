class Solution {
public:
    int rob(vector<int>& nums) {
        //分为两组，一次是[0,length-1),二是[1,length)，再比大小
        int length=nums.size();
        if(length==0) return 0;
        if(length==1) return nums[0];
        if(length==2) return max(nums[0],nums[1]);
        
        return max(myfunction(nums,0),myfunction(nums,1));
    }
    int myfunction(vector<int>& nums, int index){//
        int length=nums.size();
        vector<int> dp(length,0);
        if(index==1){//有可能抢最后一家时
            dp[0]=0;dp[1]=nums[1];
            for(int i=2;i<length;i++){
                dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            }
            return dp[length-1];
        }
        else{//有可能抢第一家时
            dp[0]=nums[0];dp[1]=max(nums[0],nums[1]);
            for(int i=2;i<length-1;i++){
                dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            }
            return dp[length-2];
        }
    }
};
