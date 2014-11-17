class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;

        stack<TreeNode*> S;
        S.push(root);

        while(!S.empty())
        {
            TreeNode *node = S.top();
            S.pop();
            
            if (NULL == node) continue;

            if (!S.empty() && S.top() == node->right)
            {
                result.push_back(node->val);
            }
            else
            {
                S.push(node->right);
                S.push(node);
                S.push(node->left);
            }
        }

        return result;
    }
};
