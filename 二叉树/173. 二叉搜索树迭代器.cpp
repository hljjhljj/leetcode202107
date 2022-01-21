//先将二叉树中序遍历一遍存储在数组种
class BSTIterator {
public:
    vector<int> tmp;
    int index;
    BSTIterator(TreeNode* root) {
        inorder(root);
        this->index=0;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        tmp.push_back(root->val);
        inorder(root->right);
    }
    
    int next() {
        return tmp[index++];
    }
    
    bool hasNext() {
        return index<tmp.size();
    }
};

//思考非递归的中序遍历怎么做的？把他拆成两部分
class BSTIterator {
public:
    TreeNode* cur;
    stack<TreeNode*> stack;
    BSTIterator(TreeNode* root) {
        this->cur=root;
    }
    
    int next() {
        while(cur){
            stack.push(cur);
            cur=cur->left;
        }
        TreeNode* temp=stack.top();
        stack.pop();
        cur=temp->right;
        return temp->val;
    }
    
    bool hasNext() {
        return cur || !stack.empty();//其实就是中序遍历里while循环的部分
    }
};
