//https://blog.csdn.net/the_ZED/article/details/105126583?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164682229016780366583488%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164682229016780366583488&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-105126583.pc_search_result_control_group&utm_term=%E5%B9%B6%E6%9F%A5%E9%9B%86&spm=1018.2226.3001.4187
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m=board.size(),n=board[0].size();
        init(m*n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X') continue;
                else if(!i || !j || i==m-1 || j==n-1){//是O并且是边缘节点
                    merge(i*n+j,m*n);
                }
                if(i-1>=0 && board[i-1][j]=='O'){
                    merge(i*n+j,(i-1)*n+j);
                }
                if(j-1>=0 && board[i][j-1]=='O'){
                    merge(i*n+j,i*n+j-1);
                }
                
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && find(i*n+j)!=m*n) board[i][j]='X';
            }
        }
    }

private:
    void init(int x){
        pre.resize(x);
        for(int i=0;i<x;i++) pre[i]=i;//默认每个节点的上司是自己
    }

    int find(int x){//找到自己的顶头上司
        if(pre[x]==x) return x;//自己就是自己的上司
        else pre[x]=find(pre[x]);
        return pre[x];
        //如果else if return find(pre[x]);会超时
        //具体看链接中的路径压缩解释，最好每个人直接连接自己的boss，不然调用链太长
    }

    void merge(int x,int y){//联通了，合并两个帮派
        int p1=find(x),p2=find(y);//找到各自的老大
        //如果老大是pre.size()-1，说明它是联通边缘节点的，那么两个帮派选老大是必须选pre.size()-1
        //否则选谁都无所谓
        if(p1==pre.size()-1) pre[p2]=p1;
        else if(p2==pre.size()-1) pre[p1]=p2;
        else pre[p2]=p1;
    }

    vector<int> pre;//指示本节点的上司
    //指定pre[m*n]为第三方头领，指出所有联通边缘的O
};

//DFS解法
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m=board.size(),n=board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][n-1]=='O') dfs(board,i,n-1);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[m-1][j]=='O') dfs(board,m-1,j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
        
    }

    void dfs(vector<vector<char>>& board,int i,int j){
        if( i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!='O')
            return;
        board[i][j]='#';
        dfs(board,i,j+1);
        dfs(board,i,j-1);
        dfs(board,i+1,j);
        dfs(board,i-1,j);
    }

};

//BFS解法
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m=board.size(),n=board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][n-1]=='O') dfs(board,i,n-1);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[m-1][j]=='O') dfs(board,m-1,j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
        
    }

    void dfs(vector<vector<char>>& board,int i,int j){
        int m = board.size(), n = board[0].size();
        deque<pair<int,int>> deque;
        deque.push_back({i,j});
        while(!deque.empty()){
            auto x=deque.front();
            deque.pop_front();
            int a=x.first,b=x.second;
            if( a<0 || a>=m || b<0 || b>=n || board[a][b]!='O') continue;
            board[a][b]='#';
            deque.push_back({a,b+1});
            deque.push_back({a,b-1});
            deque.push_back({a+1,b});
            deque.push_back({a-1,b});
        }
    }
};


//DFS另外一种容器
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m=board.size(),n=board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][n-1]=='O') dfs(board,i,n-1);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[m-1][j]=='O') dfs(board,m-1,j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
        
    }

    void dfs(vector<vector<char>>& board,int i,int j){
        int m = board.size(), n = board[0].size();
        stack<pair<int,int>> stack;
        stack.push({i,j});
        while(!stack.empty()){
            auto x=stack.top();
            stack.pop();
            int a=x.first,b=x.second;
            if( a<0 || a>=m || b<0 || b>=n || board[a][b]!='O') continue;
            board[a][b]='#';
            stack.push({a,b+1});
            stack.push({a,b-1});
            stack.push({a+1,b});
            stack.push({a-1,b});
        }
    }
};

