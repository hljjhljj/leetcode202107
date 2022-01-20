//就比46.全排列多个set去重，但是感觉不太好，投机取巧
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

//这才是合理合法的
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());//有序，让重复数字排在一起
        vector<bool> used(nums.size(),false);
        vector<int> track;
        myfunction(nums,used,track);

        return res;
    }
    void myfunction(vector<int>& nums,vector<bool>& used,vector<int>& track){
        if(track.size()==nums.size()){
            res.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //要保证相同大小的元素，只有一种排列方式！相同的元素，必须按照nums的顺序依次取
            if(used[i] || (i>=1 && nums[i]==nums[i-1] && !used[i-1])) 
                continue;//已经使用过,或者上一个元素和他相同但上一个元素还没取
            used[i]=true;
            track.push_back(nums[i]);
            myfunction(nums,used,track);
            track.pop_back();
            used[i]=false;
        }   
    }
};
