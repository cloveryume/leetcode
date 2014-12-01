class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> queP, queQ;
        queP.push(p);
        queQ.push(q);

        while (!queP.empty() && !queQ.empty()) {
            p = queP.front(); queP.pop();
            q = queQ.front(); queQ.pop();

            if (!equal(p, q)) return false;

            if (p) { queP.push(p->left); queP.push(p->right); }
            if (q) { queQ.push(q->left); queQ.push(q->right); }
        }

        return queP.empty() && queQ.empty();
    }

private:
    bool equal(TreeNode *p, TreeNode *q) {
        if (p && q) return p->val == q->val;
        if (!p && !q) return true;

        return false;
    }
};
