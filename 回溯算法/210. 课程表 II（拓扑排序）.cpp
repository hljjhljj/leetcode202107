//https://mp.weixin.qq.com/s/7nP92FhCTpTKIAplj_xWpA
class Solution {
public:
    bool hasCycle = false;
    vector<int> res;

    void travel(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<bool>& onPath){
        if(visited[node] || hasCycle || onPath[node]){
            if(onPath[node]) hasCycle = true;
            return;
        }

        visited[node] = true;
        onPath[node] = true;
        for(int i:graph[node]) travel(graph,i,visited,onPath);
        res.push_back(node);//存储的是后序遍历的结果
        onPath[node] = false;
    }

    //判断是否有环，无环才能学完
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>()); 
        for(auto i:prerequisites) graph[i[1]].push_back(i[0]); // 构建邻接表
        vector<bool> visited(numCourses, false); 
        vector<bool> onPath(numCourses, false); 

        for(int i = 0; i < numCourses; i++) travel(graph, i, visited, onPath); 

        return !hasCycle;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(canFinish(numCourses,prerequisites)){
            reverse(res.begin(),res.end());//经过倒序才是真正的学习路线
            return res;
        }
        else return vector<int>();
    }
};
