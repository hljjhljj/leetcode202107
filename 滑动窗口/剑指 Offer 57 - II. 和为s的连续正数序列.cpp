class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left=1,right=1;//[left,right)
        vector<vector<int>> res;
        int sum=0;
        while(right<=target/2+1){                
            sum+=right;
            right++;

            while(sum>=target){
                if(sum==target && (right-left)>=2){
                    vector<int> temp;
                    for(int i=left;i<right;i++){
                        temp.push_back(i);
                    }
                    res.push_back(temp);
                }
                sum-=left;
                left++;
            }
        }
        return res;
    }
};
