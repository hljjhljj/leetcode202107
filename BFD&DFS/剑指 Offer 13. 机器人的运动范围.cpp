class Solution {
public:
    int movingCount(int m, int n, int k) {
        int res=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));//记录遍历过的点
        queue<vector<int>> queue;//{x坐标,y坐标,x两位和,y两位和}
        queue.push({0,0,0,0});
        while(!queue.empty()){
            vector<int> tmp=queue.front();
            queue.pop();
            if(tmp[0]>=m || tmp[1]>=n || tmp[2]+tmp[3]>k || visited[tmp[0]][tmp[1]]) continue;
            visited[tmp[0]][tmp[1]]=true;
            res++;
            queue.push({tmp[0]+1,tmp[1],(tmp[0]+1)%10!=0?tmp[2]+1:tmp[2]-8,tmp[3]});
            queue.push({tmp[0],tmp[1]+1,tmp[2],(tmp[1]+1)%10!=0?tmp[3]+1:tmp[3]-8});
        }
        return res;
    }
};
