class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;

        if (NULL == root) return result;

        queue<TreeNode *> que;
        que.push(root);
        
        size_t len = 0;
        TreeNode *node;
    
        while (!que.empty())
        {
            vector<int> vec;

            len = que.size();
            for (size_t i = 0; i < len; ++i)
            {
                node = que.front();
                que.pop();
                vec.push_back(node->val);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            result.push_back(vec);
        }

        std::reverse(std::begin(result), std::end(result));
        return result;
    }
};
