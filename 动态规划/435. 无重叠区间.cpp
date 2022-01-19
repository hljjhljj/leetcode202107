//动态规划 复杂度为n^2，会超时，和354. 俄罗斯套娃信封问题一样
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int len=intervals.size();
        vector<int> dp(len,1);//i以前，可包含不重叠的最大数量
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){
                if(intervals[j][1]<=intervals[i][0])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return len-dp[len-1];
    }
};

//贪心算法，和452. 用最少数量的箭引爆气球一样
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });//以区间结束点升序排序，目的是，尽可能选择right更小的
        int right=intervals[0][1];
        int res=1;//不重叠区间的最大值
        for(int i=1;i<intervals.size();i++){
            //
            if(intervals[i][0]>=right){
                res++;
                right=intervals[i][1];
            }
        }
        return intervals.size()-res;
    }
};
