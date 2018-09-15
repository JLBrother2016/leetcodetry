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
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(!root) return true;
//         if(root->left == nullptr && root->right == nullptr)
//         	return true;
//         if(root->left == nullptr || root->right == nullptr)
//         	return false;
//         if(root->left->val != root->right->val)
//         	return false;

//         return isSymmetric(root->left) && 
//         	   isSymmetric(root->right);
//     }
// };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
private:
	bool isMirror(TreeNode* root1, TreeNode* root2) {
		if(!root1 && !root2) return true;
        if(root1 == nullptr || root2 == nullptr)
        	return false;

        return root1->val == root2->val &&
        	   isMirror(root1->right, root2->left) && 
        	   isMirror(root1->left, root2->right);
	}
};

class Solution {
public:

    vector<char> tree;
    
    bool isSymmetric(TreeNode* root) {
        
        return root == NULL || symmetricChecker(root->left, root->right);

    }
    
    bool symmetricChecker(TreeNode* left, TreeNode* right){
        
        if(left == NULL || right == NULL)
            return left == right;            
        if(left->val != right->val)
            return false;
        
        return symmetricChecker(left->left , right->right) && symmetricChecker(left->right, right->left);
    }

};

class Solution {
public:
    /*
    bool isMirror(TreeNode* l1, TreeNode* l2)
    {
        if(l1 == NULL && l2 == NULL) return true;
        if(l1 == NULL || l2 == NULL) return false;
        return (l1->val == l2->val) && isMirror(l1->left, l2->right) && isMirror(l1->right, l2->left);
    }
    */
    
    bool isSymmetric(TreeNode* root) 
    {
        queue<TreeNode*> q1;   // 队列
        //queue<TreeNode*> q2;
        if(root == NULL) return true;
        q1.push(root);
        q1.push(root);
        while(!q1.empty())
        {
            TreeNode* n1 = q1.front();
            q1.pop();
            TreeNode* n2 = q1.front();
            q1.pop();
            if(n1 == NULL && n2 == NULL) continue;
            if(n1 == NULL || n2 == NULL) return false;
            if(n1->val != n2->val) {
                return false;
            }
            q1.push(n1->left);
            q1.push(n2->right);
            q1.push(n1->right);
            q1.push(n2->left);
        }
        return true;
    }
    
};


int main(int argc, char const *argv[])
{
	TreeNode* p = createTree({1, 2, 2, 3, 4, 4, 3});
	levelorderTraverseTree(p);
	cout << endl;
	cout << Solution().isSymmetric(p) << endl;

	return 0;
}

