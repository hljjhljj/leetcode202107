class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;
        else return myfunction(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
    bool myfunction(TreeNode* A, TreeNode* B){
        if(!B) return true;
        else if(!A || A->val!=B->val) return false;
        else return myfunction(A->left,B->left) && myfunction(A->right,B->right);
    }
};
