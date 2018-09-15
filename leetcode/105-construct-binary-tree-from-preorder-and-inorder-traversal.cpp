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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(0, 0, preorder.size()-1, preorder, inorder);
    }
private:
	TreeNode* buildTree(int preStart, int inStart, int inEnd,
						vector<int>& preorder, vector<int>& inorder) {
		if(preStart > preorder.size() - 1 || inStart > inEnd) {
			return nullptr;
		}
		TreeNode* root = (TreeNode*) new TreeNode(preorder[preStart]);
		int inIndex = 0;
		for(int i = inStart; i <= inEnd; ++i) {
			if(inorder[i] == root->val) {
				inIndex = i;
			}
		}
		root->left = buildTree(preStart+1, inStart, inIndex-1,
			                  preorder, inorder);
		root->right = buildTree(preStart+inIndex-inStart+1, inIndex+1,
								inEnd, preorder, inorder);

		return root;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> iv1{3, 9, 20, 15, 7};
	vector<int> iv2{9, 3, 15, 20, 7};
	TreeNode* node = Solution().buildTree(iv1, iv2);
	levelorderTraverseTree(node);

	return 0;
}

