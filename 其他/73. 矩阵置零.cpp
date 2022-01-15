class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row_flag=false,col_flag=false;
        int x=matrix.size(),y=matrix[0].size();
        for(int j=0;j<y;j++){
            if(matrix[0][j]==0){
                row_flag=true;
                break;
            }
        }
        for(int i=0;i<x;i++){
            if(matrix[i][0]==0){
                col_flag=true;
                break;
            }
        }
        for(int i=1;i<x;i++){
            for(int j=1;j<y;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<x;i++){
            for(int j=1;j<y;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(row_flag){
            for(int j=0;j<y;j++){
                matrix[0][j]=0;
            }
        }
        if(col_flag){
            for(int i=0;i<x;i++){
                matrix[i][0]=0;
            }
        }
    }
};
