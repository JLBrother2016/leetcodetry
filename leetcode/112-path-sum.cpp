#include "../leetcodeutil.h"

class Solution {
public:   // 只需要找到一个有没有路径和为sum
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(root->val == sum && !root->left && root->right) return true;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

class Solution {
public:
    bool helper(TreeNode* root, int curr, int sum){
        curr = curr + root->val;
        if(curr!=sum && root->left==NULL && root->right==NULL){return false;}
        else if(curr==sum && root->left==NULL && root->right==NULL){return true;}
        else if(root->left==NULL){return helper(root->right,curr,sum);}
        else if(root->right==NULL){return helper(root->left,curr,sum);}
        else{return helper(root->left,curr,sum) || helper(root->right,curr,sum);}
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){return false;}
        return helper(root,0,sum);
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
