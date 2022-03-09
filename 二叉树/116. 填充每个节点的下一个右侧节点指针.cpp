class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return root;
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            for(int i = 0; i < size; i++) {
                Node* node = Q.front();
                Q.pop();
                // 连接
                if (i < size - 1) node->next = Q.front();
                // 拓展下一层节点
                if (node->left != nullptr) Q.push(node->left);
                if (node->right != nullptr) Q.push(node->right);
            }
        }
        return root;
    }
};
