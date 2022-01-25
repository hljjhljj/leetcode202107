//还有别的答案我看不懂，只能计数
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) nums[index++]=0;
            else if(nums[i]==1) count++;//计算1的数量
        }
        for(int i=index;i<nums.size();i++){
            if(count-->0) nums[i]=1;
            else nums[i]=2;
        }
        return;
    }
};
