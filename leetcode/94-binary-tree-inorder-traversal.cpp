#include "../leetcodeutil.h"

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root == nullptr) return {};
//         vector<int> ans;
//         inorderTraversal(root, ans);

//         return ans;
//     }
// private:
// 	void inorderTraversal(TreeNode* node, vector<int>& ans) {
// 		if(node == nullptr) return;
// 		inorderTraversal(node->left, ans);
// 		ans.push_back(node->val);
// 		inorderTraversal(node->right, ans);
// 	}
// };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        TreeNode* p = root;
        stack<TreeNode*> st;
        // 栈中有元素或者根缺点存在
        while(!st.empty() || p) {
        	if(p) { //一直遍历到左子树的最下边
        		st.push(p); //边遍历边保存到栈中
        		p = p->left;
        	} else { //已经到达左子树最下边, 这时需要出栈
        		p = st.top();
        		st.pop();
        		ans.push_back(p->val);
        		p = p->right; //进入右子树, 进入新一轮的遍历
        	}
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
	

	return 0;
}

