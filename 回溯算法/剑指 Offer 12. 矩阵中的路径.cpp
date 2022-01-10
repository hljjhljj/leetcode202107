class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(myfunction(board,word,i,j,0)) return true;
        return false;
    }
    
    int dm[4] = {-1,0,1,0}, dn[4] = {0,1,0,-1}; //方向数组
    bool myfunction(vector<vector<char>>& board, string word, int m, int n, int position){
        if(position>=word.size()) return true;
        if(m>=board.size() || m<0 || n>=board[0].size() || n<0) return false;
        if(board[m][n]!=word.at(position)) return false;
        for(int i = 0; i < 4; i++){
            board[m][n]='.';
            if(myfunction(board,word,m+dm[i],n+dn[i],position+1)) return true;
            board[m][n]=word.at(position);
        }
        return false;
    }
};
