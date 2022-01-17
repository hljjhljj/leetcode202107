class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        //其实本质就是两个dp数组，分别维护 i 左侧、右侧的乘积和(不包含i)
        int len=a.size();
        vector<int> dpleft(len,1);
        vector<int> dpright(len,1);
        for(int i=1;i<len;i++){
            dpleft[i]=dpleft[i-1]*a[i-1];
        }
        for(int j=len-2;j>=0;j--){
            dpright[j]=dpright[j+1]*a[j+1];
        }
        vector<int> res;
        for(int i=0;i<len;i++){
            res.push_back(dpleft[i]*dpright[i]);
        }
        return res;
    }
};
