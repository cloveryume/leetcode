class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;                                                                                                                                                                
        stack<int> si; 

        stack<TreeNode*> st; 
        st.push(root);
        TreeNode *node;
        while (!st.empty())
        {   
            node = st.top();
            st.pop();

            if (NULL == node) continue;

            st.push(node->left);
            st.push(node->right);
            si.push(node->val);
        }   

        while (!si.empty())
        {   
            vec.push_back(si.top());
            si.pop();
        }   

        return vec;
    }
};
