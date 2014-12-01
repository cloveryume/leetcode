class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        deque<TreeNode *> q1;
        q1.push_back(root);

        while (!q1.empty()) {
            deque<TreeNode *> q2;

            for (int i = q1.size() / 2; i >=0; --i)
            {
                int j = q1.size() - 1 - i;
                if (i == j) { 
                    if (q1[i]) {
                        q2.push_back(q1[i]->left); 
                        q2.push_back(q1[i]->right); 
                    }
                    continue; 
                }

                if (!equal(q1[i], q1[j])) return false;

                if (q1[i]) { 
                    q2.push_front(q1[i]->right); 
                    q2.push_front(q1[i]->left); 
                }
                if (q1[j]) { 
                    q2.push_back(q1[j]->left); 
                    q2.push_back(q1[j]->right); 
                }
            }
            q1.swap(q2);
        }

        return true;
    }

private:
    bool equal(TreeNode *p, TreeNode *q) {
        if (p && q) return p->val == q->val;
        if (!p && !q) return true;

        return false;
    }
};
