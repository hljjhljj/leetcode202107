//需要求下一个更大的或者更小的时候可以用单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> stack;
        for(int i=0;i<temperatures.size();i++){
            while(!stack.empty() && temperatures[i]>temperatures[stack.top()]){
                int k=stack.top();
                res[k]=i-k;
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }
};
