class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //就是求不重叠的气球的总数
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return  a[1] < b[1];
        });
        int right = points[0][1], cnt = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > right) {
                cnt++;
                right = points[i][1];
            }
        }
        return cnt;

    }
};
