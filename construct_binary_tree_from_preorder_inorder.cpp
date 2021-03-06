class Solution {
public:
    struct Elem
    {
        TreeNode **proot;       // 子树根节点的存储位置
        int pre_begin;          // 子树先序序列起始在preorder vector中的位置
        int in_begin;           // 子树中序序列起始在inorder vector中的位置
        int size;               // 子树的节点个数
    };

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.size() == 0) return NULL;

        TreeNode *root;
        Elem e = {&root, 0, 0, preorder.size()};

        stack<Elem> s;
        s.push(e);

        while (!s.empty())
        {
            e = s.top();
            s.pop();

            if (e.size == 0) { *(e.proot) = NULL; continue; }

            int val = preorder[e.pre_begin];        // 取根
            TreeNode *root = new TreeNode(val);
            *(e.proot) = root;

            Elem left, right;       // 左右子树
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

            left.pre_begin = e.pre_begin + 1;
            left.in_begin = e.in_begin;
            right.pre_begin = left.pre_begin + left.size;
            right.in_begin = left.in_begin + left.size + 1;

            s.push(right);
            s.push(left);
        }

        return root;
    }
};
