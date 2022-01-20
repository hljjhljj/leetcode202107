//就比46.全排列多个set去重
class Solution {
public:
    set<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        vector<int> track;
        myfunction(nums,used,track);
        vector<vector<int>> res1;
        for(auto r:res){
            res1.push_back(r);
        }
        return res1;
    }
    void myfunction(vector<int>& nums,vector<bool>& used,vector<int>& track){
        if(track.size()==nums.size()){
            res.insert(track);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;//已经使用过
            used[i]=true;
            track.push_back(nums[i]);
            myfunction(nums,used,track);
            track.pop_back();
            used[i]=false;
        }   
    }
};
