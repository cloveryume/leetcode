class Solution {
public:
    struct Elem
    {
        TreeNode **proot;   // 子树根节点的存储位置
        int in_begin;       // 子树中序序列开始在inorder vector中的位置
        int post_end;       // 子树后序序列末尾在postorder vector中的位置
        int size;           // 子树的节点个数
    };

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0) return NULL;

        TreeNode *root;
        Elem e = {&root, 0, postorder.size(), inorder.size()};

        stack<Elem> s;
        s.push(e);

        while (!s.empty())
        {
            e = s.top();
            s.pop();

            if (e.size == 0) { *(e.proot) = NULL; continue; }

            int val = postorder[e.post_end - 1];
            TreeNode *root = new TreeNode(val);
            *(e.proot) = root;

            Elem left, right;
            left.proot = &(root->left);
            right.proot = &(root->right);

            int i;
            left.size = 0;
            for (i = e.in_begin; i < e.in_begin + e.size; ++i)
            {
                if (inorder[i] == val)
                    break;

                ++left.size;
            }

            right.size = e.size - left.size - 1;

            left.in_begin = e.in_begin;
            right.post_end = e.post_end - 1;
            left.post_end = e.post_end - right.size - 1;
            right.in_begin = e.in_begin + left.size + 1;

            s.push(right);
            s.push(left);
        }

        return root;
    }
};
