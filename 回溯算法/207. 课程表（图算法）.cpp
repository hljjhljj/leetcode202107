//是否能学完，判断是否存在循环依赖（环）即可
class Solution {
public:
    bool hasCycle = false;

    void travel(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<bool>& onPath){
        if(visited[node] || hasCycle || onPath[node]){
            if(onPath[node]) hasCycle=true;
            return;
        }

        visited[node] = true;
        onPath[node] = true;//用于判断是否在本次路径上
        for(int i:graph[node]) 
            travel(graph,i,visited,onPath);
        onPath[node] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>()); 
        for(auto i:prerequisites) graph[i[1]].emplace_back(i[0]); // 构建邻接表
        vector<bool> visited(numCourses, false); 
        vector<bool> onPath(numCourses, false); 

        for(int i = 0; i < numCourses; i++) //以每个节点为起始遍历图，visited过的图就不用visit了
            travel(graph, i, visited,onPath); 

        return !hasCycle;
    }
};
