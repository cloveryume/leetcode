class Solution {
public:
    int minDepth(TreeNode *root) {
        if (NULL == root) return 0;

        queue<TreeNode *> nodes;
        nodes.push(root);

        size_t length = 0;
        size_t count;
        bool finish = false;

        while(!finish && (count = nodes.size()) > 0)
        {
            ++length;

            for (int i = 0; i < count; ++i)
            {
                TreeNode *node = nodes.front();
                nodes.pop();
                
                if (node->left == NULL && node->right == NULL)
                {
                    finish = true;
                    break;
                }

                if (node->left != NULL) nodes.push(node->left);
                if (node->right!= NULL) nodes.push(node->right);
            }
        }

        return length;
    }
};
