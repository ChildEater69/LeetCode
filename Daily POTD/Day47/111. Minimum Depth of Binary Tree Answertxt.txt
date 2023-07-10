class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=minDepth(root->left);
        int rh=minDepth(root->right);
        if(lh==0) return 1+rh; //lh=0 means there is no left subtree,so we cannot compare its height to right subtree
        else if(rh==0) return 1+lh; //rh=0 means there is no right subtree
        else return 1+ min(lh,rh);
    }
};