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
// // 树的题目一般都用递归求解, 递归判断左右子树是否合法
// // 1. 限制树的范围
// // 2. 
// public:
//     bool isValidBST(TreeNode* root) {
//         return isValidBST(root, LLONG_MIN, LLONG_MAX);
//     }
// private:
// 	bool isValidBST(TreeNode* root, long min_val, long max_val) {
// 		if(!root) return true;
// 		if(root->val <= min_val || root->val >= max_val)
// 			return false;
// 		// 限制区间
// 		return isValidBST(root->left, min_val, root->val) &&
// 			   isValidBST(root->right, root->val, max_val);
// 	}
// };

// class Solution {
// // 树的题目一般都用递归求解, 递归判断左右子树是否合法
// // 1. 限制树的范围
// // 2. 利用中序遍历
// public:
//     bool isValidBST(TreeNode* root) {
//         return isValidBST(root, nullptr, nullptr);
//     }
// private:
// 	bool isValidBST(TreeNode* root, int* min_val, int* max_val) {
// 		if(!root) return true;
// 		if((min_val && root->val <= *min_val) || 
// 		   (max_val && root->val >= *max_val))
// 			return false;
// 		// 限制区间
// 		return isValidBST(root->left, min_val, &root->val) &&
// 			   isValidBST(root->right, &root->val, max_val);
// 	}
// };

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		prev_ = nullptr;
		return inOrder(root);
	}
private:
	TreeNode* prev_;
	bool inOrder(TreeNode* root) {
		if(!root) return true;
		if(!inOrder(root->left))  // 如果左子树不满足中序
			return false;
		if(prev_ && root->val <= prev_->val) //中序时, 根节点应该比前一个节点大
			return false;
		prev_ = root;

		return inOrder(root->right);
	}
};


int main(int argc, char const *argv[])
{
	TreeNode* node = createTree({2, 1, 3});
	cout << Solution().isValidBST(node) << endl;

	return 0;
}
