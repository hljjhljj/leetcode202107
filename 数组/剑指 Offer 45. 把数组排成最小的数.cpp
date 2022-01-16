class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res;
        fastsort(nums,0,nums.size()-1);
        for(auto num:nums){
            res+=to_string(num);
        }
        return res;
    }
    void fastsort(vector<int>& nums,int left, int right){
        if(left>=right) return;
        int i=left,j=right,base=nums[left];
        while(i<j){
            while(i<j && myfunction(nums[j],base)) j--;
            while(i<j && !myfunction(nums[i],base)) i++;
            if(i<j) swap(nums[i],nums[j]);
        }
        nums[left]=nums[i];
        nums[i]=base;
        fastsort(nums,left,i-1);
        fastsort(nums,i+1,right);
    }

    //stoi是字符串转数字
    bool myfunction(int x, int y){//判断大小，x>y返回true,x<=y返回false
        string s1=to_string(x)+to_string(y);
        string s2=to_string(y)+to_string(x);
        // return stoi(s1)>stoi(s2);//不行，好像会导致溢出
        //xy>yx的话认为x>y
        if(s1.compare(s2)>0) return true;//if(s1>s2) return true;也行
        //s1.compare(s2)>0表示s1大，=0表示等于，<0表示s1小
        else return false;
    }
};
