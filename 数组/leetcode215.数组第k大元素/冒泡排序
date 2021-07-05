class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size()-1;i++){
            bool flag=true;
            for(int j=1;j<nums.size()-i;j++){
                if(nums[j-1]<nums[j]){
                    int temp=nums[j-1];
                    nums[j-1]=nums[j];
                    nums[j]=temp;
                    flag=false;
                }
            }
            if(flag) break;
        }
        return nums[k-1];

    }
};
