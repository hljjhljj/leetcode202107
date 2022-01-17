//没太看懂，结合98. 验证二叉搜索树思考一下
class Solution {
public:
    int index;
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()<=1) return true;
        index=postorder.size()-1;//倒序遍历数组，根→右子树→左子树
        myfunction(postorder,INT_MIN,INT_MAX);
        return index<0;//表示遍历完
    }
    void myfunction(vector<int>& postorder, int min, int max){
        if(index<0) return ;//已经遍历完了
        int tmp=postorder[index];
        if(tmp<=min || tmp>=max) return;
        index--;
        myfunction(postorder,tmp,max);//遍历右子树
        myfunction(postorder,min,tmp);//遍历左子树
    }
};
