class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (NULL == root) return 0;

        queue<int> iq;
        queue<TreeNode *> nq;
        int sum = 0;
        int len = 0;
        int tmp;
        TreeNode *node;

        iq.push(root->val);
        nq.push(root);

        while (!nq.empty())
        {
            len = nq.size();
            for (size_t i = 0; i < len; ++i)
            {
                node = nq.front();
                nq.pop();

                tmp = iq.front();
                iq.pop();

                if (!node->left && !node->right) // 叶节点, 结算这条路径
                {
                    sum += tmp;
                    continue;
                }

                if (node->left)
                {
                    nq.push(node->left);
                    iq.push(tmp * 10 + node->left->val);
                }

                if (node->right)
                {
                    nq.push(node->right);
                    iq.push(tmp * 10 + node->right->val);
                }
            }
        }
        
        return sum;
    }
};
