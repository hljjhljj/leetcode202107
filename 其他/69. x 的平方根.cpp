class Solution {
public:
    int mySqrt(int x) {
        int left=0,right=x,res;
        while(left<=right){
            int mid=left+(right-left)/2;
            if((long long)mid*mid <= x){
                res=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return res;
    }
};


class Solution {
public:
    int mySqrt(int x) {
        int left=0,right=x,res;
        while(left<=right){
            int mid=left+(right-left)/2;
            if((long long)mid*mid == x) return mid;
            if((long long)mid*mid < x) left=mid+1;
            else right=mid-1;
        }
        return right;
    }
};
