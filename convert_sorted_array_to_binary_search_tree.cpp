class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size());
    }

private:
    TreeNode *sortedArrayToBST(vector<int> &num, int low, int high) {
        if (low >= high) return NULL;

        int mid = (low + high) / 2;

        TreeNode *node = new TreeNode(num[mid]);
        node->left = sortedArrayToBST(num, low, mid);
        node->right = sortedArrayToBST(num, mid+1, high);

        return node;
    }
};
