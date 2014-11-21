class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (NULL == root) return 0;

        queue<TreeNode *> que;
        que.push(root);

        int depth = 0;
        size_t len = 0;
        TreeNode *node = NULL;

        while(!que.empty())
        {
            len = que.size();
            ++depth;

            for (size_t i = 0; i < len; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return depth;
    }
};
