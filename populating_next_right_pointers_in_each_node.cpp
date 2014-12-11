class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;

        queue<TreeLinkNode *> que;
        que.push(root);
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; ++i) {
                TreeLinkNode *node = que.front();
                que.pop();
                node->next = i == len - 1 ? NULL : que.front();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
    }
};
