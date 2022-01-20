class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());//让相同的元素排在一起
        
        vector<int> track;
        myfunction(candidates,target,0,track);
        return res;
    }
    void myfunction(vector<int>& candidates, int target, int index, vector<int>& track){
        if(target==0){
            res.push_back(track);
            return;
        }
        if(target<0) return ;//已经排序了，所以可以剪枝，否则就超时
        for(int i=index;i<candidates.size();i++){
            //为防止重复，假设{1，1，2，4，7},那么index的取值只能是0，2，3，4。
            //否则以第二个1为开头的组合会和前面重复
            if(i-1>=index && candidates[i-1]==candidates[i]) continue;
            track.push_back(candidates[i]);
            myfunction(candidates,target-candidates[i],i+1,track);
            track.pop_back();
        }
    }
};
