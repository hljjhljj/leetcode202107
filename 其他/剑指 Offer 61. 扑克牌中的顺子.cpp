class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_set<int> set;
        int minnum=14,maxnum=0;
        for(auto num:nums){
            if(num==0) continue;
            minnum=min(minnum,num);
            maxnum=max(maxnum,num);
            if(set.find(num)!=set.end()) return false;
            set.insert(num);
        }
        return maxnum-minnum<5;
    }
};
