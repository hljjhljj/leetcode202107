class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xy=0;
        for(auto n:nums){
            xy=xy^n;//结果就是那两个数的异或x^y
        }
        int flag=1;
        while((xy&flag)==0) flag=flag<<1;//不能写while((xy && flag)==0)
        //找到最低位的1，其实任意一位即可，表明对x和y来说这一位是不同的
        //然后我们按照这一位把数据分成两组，就变成了找只有一个数重复一次的情况
        int x=0,y=0;
        for(auto n:nums){
            if(n&flag) x=x^n;//不能写if((n&flag)==1) 
            else y=y^n;
        }
        return vector<int>{x,y};
    }
};
