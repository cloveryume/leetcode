// 栈模拟递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;

        stack<TreeNode *> S;
        S.push(root);
        while(!S.empty())
        {
            TreeNode *node = S.top();
            S.pop();

            if (NULL == node) continue;

            result.push_back(node->val);
            S.push(node->right);
            S.push(node->left);
        }

        return result;
    }
};
