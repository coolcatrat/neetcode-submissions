class Solution {
    unordered_map<int,int> pos;   // inorder value -> index
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, int inL, int inR) {
        if (inL > inR) return nullptr;          // empty range -> no node

        int rootVal = preorder[preIdx++];        // consume next preorder element
        TreeNode* root = new TreeNode(rootVal);
        int mid = pos[rootVal];                  // root's spot in inorder

        // left first: preorder lays out the full left subtree before any right node
        root->left  = build(preorder, inL, mid - 1);
        root->right = build(preorder, mid + 1, inR);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};