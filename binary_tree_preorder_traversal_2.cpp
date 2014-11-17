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
            goAlongLeft(node, S, result);
        }

        return result;
    }

private:
    void goAlongLeft(TreeNode *node, stack<TreeNode*>& S, vector<int>& result)
    {
        while(node != NULL)
        {
            result.push_back(node->val);
            S.push(node->right);
            node = node->left;
        }
    }
}; 
