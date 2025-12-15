class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are null, trees are same
        if (p == nullptr && q == nullptr) return true;
        
        // If one is null and other is not, trees differ
        if (p == nullptr || q == nullptr) return false;
        
        // If values differ, trees differ
        if (p->val != q->val) return false;
        
        // Check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
