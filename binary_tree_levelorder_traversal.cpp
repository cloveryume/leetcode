class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        queue<TreeNode *> nodes;
        
        if (NULL == root) return result;

        nodes.push(root);
        
        bool finish = false;
        size_t last_quque_size;
        while ((last_quque_size = nodes.size()) > 0)
        {
            result.push_back(vector<int>());
            for (int i = 0; i < last_quque_size; ++i)
            {
                TreeNode *node = nodes.front();
                nodes.pop();

                result.back().push_back(node->val);

                if (node->left != NULL) nodes.push(node->left);
                if (node->right!= NULL) nodes.push(node->right);
            }
        }
    }

    return result;
};
