class cmp{
public:
    bool operator()(const pair<int, int>& m, const pair<int, int>& n)          
    {
        return m.second > n.second;
    }
};         //定义一个比较的类
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i ++)
        {
            hash[nums[i]] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;//小根堆
        //比较函数加在外面，就不用加decltype
        for(auto [u, v] : hash)
        {
            if(q.size() < k)
                q.emplace(u, v);
            else if(v > q.top().second)
            {
                q.pop();
                q.emplace(u, v);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
