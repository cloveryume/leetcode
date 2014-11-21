class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (NULL == root) return false;

        queue<TreeNode *> nq;
        queue<int> iq;
        int len;
        bool find = false;
        TreeNode *node;
        int path_sum;

        nq.push(root);
        iq.push(root->val);

        while(!find && !nq.empty())
        {
            len = nq.size();
            for (int i = 0; i < len; ++i)
            {
                node = nq.front();  
                nq.pop();
                path_sum = iq.front();   
                iq.pop();

                if (!node->left && !node->right) // 叶节点，判别该路径和是否等于sum
                {
                    find = path_sum == sum;
                    if (find) 
                        break;
                    else 
                        continue;
                }

                if (node->left)
                {
                    nq.push(node->left);
                    iq.push(path_sum + node->left->val);
                }
                
                if (node->right)
                {
                    nq.push(node->right);
                    iq.push(path_sum + node->right->val);
                }
            }
        }

        return find;
    }
};
