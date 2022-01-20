class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board,0,0);
    }
    bool isValid(vector<vector<char>>& board,int row, int col, char c){//判断此位置是否有效
        for(int i=0;i<9;i++){
            if(board[row][i]==c) return false;//同行是否有重复
            if(board[i][col]==c) return false;//同列是否有重复
            if(board[(row/3)*3+i/3][(col/3)*3+i%3]==c) return false;//所在方格内有重复
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board,int row,int col){
        if(row>=board.size()) return true;
        if(col>=board[0].size()) return backtrack(board,row+1,0);
    
        if(board[row][col]!='.') return backtrack(board,row,col+1);//不用处理
        for(char c='1';c<='9';c++){
            if(!isValid(board,row,col,c)) continue;
            board[row][col]=c;
            if(backtrack(board,row,col+1)) return true;
            board[row][col]='.';
        }
        return false;
    }
};
