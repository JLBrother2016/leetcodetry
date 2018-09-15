#include "../leetcodeutil.h"

using namespace std;

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
//     int maxDepth(TreeNode* root) {
//         if(!root) return 0;
//         int ans = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         int len = 1;
//         while(!q.empty()) {
//         	int tmp = len;
//         	len = 0;
//         	++ans;
//         	for(int i = 0; i < tmp; ++i) {
//         		TreeNode* curr = q.front();
//         		q.pop();
//         		if(curr->left) {
//         			q.push(curr->left);
//         			++len;
//         		}
//         		if(curr->right) {
//         			q.push(curr->right);
//         			++len;
//         		}
//         	}
//         }

//         return ans;
//     }
// };
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if(!root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

int main(int argc, char const *argv[])
{
	

	return 0;
}

