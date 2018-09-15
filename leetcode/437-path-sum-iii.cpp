#include "../leetcodeutil.h"

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> tmp;
        pathSum(root, sum, 0, tmp, res);

        return res;
    }
private:
    void pathSum(TreeNode* node, int sum, int curSum,
                 vector<TreeNode*> &tmp, int &res) {
        if(!node) return;
        curSum += node->val;
        tmp.push_back(node);
        if(curSum == sum) ++res;
        int t = curSum;
        for(int i = 0; i < tmp.size() - 1; ++i) {
            t -= tmp[i]->val;
            if(t == sum) ++res;
        }
        pathSum(node->left, sum, curSum, tmp, res);
        pathSum(node->right, sum, curSum, tmp,res);

        tmp.pop_back();
    }

};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        return helper(root, sum, 0, m);
    }
    int helper(TreeNode* node, int sum, int curSum, unordered_map<int, int>& m) {
        if (!node) return 0;
        curSum += node->val;
        int res = m[curSum - sum];
        ++m[curSum];
        res += helper(node->left, sum, curSum, m) + helper(node->right, sum, curSum, m);
        --m[curSum];
        return res;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int sumUp(TreeNode* node, int pre, int& sum) {
        if (!node) return 0;
        int cur = pre + node->val;
        return (cur == sum) + sumUp(node->left, cur, sum) + sumUp(node->right, cur, sum);
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
