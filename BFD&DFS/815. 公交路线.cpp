class Solution {
public:
    //每趟公交为一个点，如果两个公交有相交的站则该两点相连
    //就变成了一个图中两点求最短路径的问题（BFS可解）
    //实际上，会有多个source和target，要以每个source为起点开始向外BFS
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n=routes.size();
        vector<vector<int>> edge(n,vector<int>(n));//存储图
        unordered_map<int,vector<int>> rec;//key=某个站点，value=经过此站的所有公交
        for(int i=0;i<n;i++){
            for(auto site:routes[i]){
                for(auto j:rec[site]){
                    edge[i][j]=1;
                    edge[j][i]=1;
                }
                rec[site].push_back(i);
            }
        }
        queue<int> queue;//BFS用的队列
        vector<int> dis(n,-1);//key=某个站点，value=到此站的最小距离
        for(int bus:rec[source]){
            queue.push(bus);
            dis[bus]=1;
        }
        while(!queue.empty()){
            int bus=queue.front();
            queue.pop();
            for(int i=0;i<n;i++){
                if(edge[bus][i] && dis[i]==-1){
                    dis[i]=dis[bus]+1;
                    queue.push(i);
                }
            }
        }
        int res=INT_MAX;
        for(int bus:rec[target]){
            if(dis[bus]!=-1){
                res=min(res,dis[bus]);
            }
        }
        return res==INT_MAX?-1:res;
    }
};
