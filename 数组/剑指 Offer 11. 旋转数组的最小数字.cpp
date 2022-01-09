//和153不一样，这里的元素可能重复
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left=0,right=numbers.size()-1;
        int mid;
        while(left<right){
            mid=(left+right)/2;
            if(numbers[mid]>numbers[right]) left=mid+1;
            else if(numbers[mid]<numbers[right]) right=mid;
            else if(numbers[mid]==numbers[right]) right--;//右边界向左收缩
        }
        return numbers[left];
    }
};
