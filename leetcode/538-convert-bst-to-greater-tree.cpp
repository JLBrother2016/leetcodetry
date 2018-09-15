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
// 思路, 先求出所有结点的和, 中序求和再求差, 节点值再加上这个差
// 但是为了优化, 可以选用逆中序的方法, 直接右根左来求解
// 递归求解
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return root;
        int ans = 0;
        dfs(root, ans);
        return root;
    }
private:
    void dfs(TreeNode* node, int& ans) {
        if(node == nullptr) return;
        dfs(node->right, ans);
        node->val += ans;
        ans = node->val;
        dfs(node->left, ans);
    }
};

class Solution {
// 思路, 先求出所有结点的和, 中序求和再求差, 节点值再加上这个差
// 但是为了优化, 可以选用逆中序的方法, 直接右根左来求解
// 递归求解
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return root;
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);

        return root;
    }
private:
    int sum = 0;
};

class Solution {
// 思路, 先求出所有结点的和, 中序求和再求差, 节点值再加上这个差
// 但是为了优化, 可以选用逆中序的方法, 直接右根左来求解
// 递推求解
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return root;
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while(p || !st.empty()) {
            while(p) {
                st.push(p);
                p = p->right;
            }
            p = st.top();
            st.pop();
            p->val ++ sum;
            sum = p->val;
            p = p->left;
        }

        return root;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* node = createTree({5, 2, 13});
    TreeNode* ans = Solution().convertBST(node);
    levelorderTraverseTree(ans);

    return 0;
}

