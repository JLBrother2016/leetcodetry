#include "../leetcodeutil.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr) return false;
        if(t == nullptr) return true;
        queue<TreeNode *> q;
        TreeNode *curr;
        q.push(s);
        while (!q.empty()) {
            curr = q.front();
            if(isSametree(curr, t)) return true;
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
            q.pop();
        }

        return false;
    }
private:
    bool isSametree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr) return false;
        if(t == nullptr) return false;
        if(s->val != t->val) return false;
        return isSametree(s->left, t->left) &&
               isSametree(s->right, t->right);
    }
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if(isSame(s, t)) {          //用递归来进行遍历, 如果有一个子树相同则直接返回true
            return true;
        }    // 看看左子树相同不, 再看看右子树相同不 
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:    
    bool isSame(TreeNode* s, TreeNode* t) {
        if(!s || !t) return s == t;
        else if(s -> val != t -> val) return false;
        return isSame(s-> left, t -> left) && isSame(s -> right, t -> right);
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
