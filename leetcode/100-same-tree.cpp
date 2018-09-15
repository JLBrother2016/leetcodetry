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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val)
        	return false;

        return isSameTree(p->left, q->left) &&
        	   isSameTree(p->right, q->right);
    }
};

int main(int argc, char const *argv[])
{
	TreeNode* p = createTree({1, 2, 3});
	TreeNode* q = createTree({1, 2, 3, 4});

	cout << Solution().isSameTree(p, q) << endl;

	return 0;
}
