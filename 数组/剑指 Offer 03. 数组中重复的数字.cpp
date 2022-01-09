//方法1：用set
//方法2：为什么不把他们置为负数？为0的时候不可行
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            int num=nums[i]%len;
            if(nums[num]>=len) return num;
            else nums[num]=nums[num]+len;
        }
        return -1;
    }
};
