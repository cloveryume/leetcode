class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (NULL == root) return true;

        stack<TreeNode* > s;
        TreeNode *node = root;
        int lastVal;
        bool lastValInit = false;

        while (true) {
            goAlongLeftBranch(node, s);

            if (s.empty()) break;

            node = s.top(); s.pop();

            if (lastValInit) {
                if (node->val <= lastVal)  return false;
                lastVal = node->val;
            }
            else {
                lastValInit = true;
                lastVal = node->val;
            }
            
            node = node->right;
        }

        return true;
    }
private:
    void goAlongLeftBranch(TreeNode *node, stack<TreeNode *>& s) {
        while(node != NULL) { s.push(node); node = node->left; }
    }
};
