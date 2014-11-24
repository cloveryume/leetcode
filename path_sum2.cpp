class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;

        if (NULL == root) return result;

        queue<TreeNode *> nodes;
        nodes.push(root);

        queue<vector<int> > paths;
        paths.push(vector<int>(1, root->val) );

        while(!nodes.empty())
        {
            TreeNode *node = nodes.front();
            vector<int>& vec = paths.front();

            if (!node->left && !node->right)
            {
                if (calPathSum(vec) == sum)
                    result.push_back(vec);
            }

            if (node->left)
            {
                vector<int> lvec(vec);
                lvec.push_back(node->left->val);
                paths.push(lvec);

                nodes.push(node->left);
            }

            if (node->right)
            {
                vector<int> rvec(vec);
                rvec.push_back(node->right->val);
                paths.push(rvec);

                nodes.push(node->right);
            }

            nodes.pop();
            paths.pop();
        }

        return result;
    }

private:
    int calPathSum(vector<int>& vec)
    {
        int ret = 0;

        for (int i = 0; i < vec.size(); ++i)
            ret += vec[i];

        return ret;
    }
};
