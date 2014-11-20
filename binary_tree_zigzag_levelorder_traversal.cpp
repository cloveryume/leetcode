class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;

        deque<TreeNode *> que;
        que.push_back(root);

        bool reverse = false; // 本轮是否要逆序
        size_t len;
        TreeNode *node;

        while ((len = que.size()) > 0)
        {
            vector<int> vec;
            for (int i = 0; i < len; ++i)
            {
                if (reverse)
                {
                    node = que.back();
                    que.pop_back();
                    if (NULL != node)
                    {
                        vec.push_back(node->val);
                        que.push_front(node->right);
                        que.push_front(node->left);
                    }
                }
                else
                {
                    node = que.front();
                    que.pop_front();
                    if (NULL != node)
                    {
                        vec.push_back(node->val);
                        que.push_back(node->left);
                        que.push_back(node->right);
                    }
                }
            }

            if (!vec.empty()) result.push_back(vec);
                
            reverse = !reverse;
        }

        return result;
    }
};
