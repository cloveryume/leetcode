class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;

        stack<TreeNode*> S;
        TreeNode *node = root;
        while (true)
        {
            goAlongLeftBranch(node, S);
            
            if (S.empty()) break;

            node = S.top();
            S.pop();
            result.push_back(node->val);

            node = node->right;
        }

        return result;
    }
private:
    void goAlongLeftBranch(TreeNode *node, stack<TreeNode*>& S)
    {
        while(NULL != node)
        {
            S.push(node);
            node = node->left;
        }
    }
};
