#include "../leetcodeutil.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};

        vector<vector<int>> ans;
        vector<int> temp;
        pathSum(root, sum, temp, ans);

        return ans;
    }
private:
    void pathSum(TreeNode* node, int sum, vector<int> &temp, 
                 vector<vector<int>> &ans) {
        if(!node) return;
        temp.push_back(node->val);
        if(!node->right && !node->left && sum == node->val) {
            ans.push_back(temp);
        }
        pathSum(node->left, sum - node->val, temp, ans);
        pathSum(node->right, sum - node->val, temp, ans);
        temp.pop_back();
    }
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;  // 保存结果
        vector<TreeNode*> s;
        TreeNode *cur = root, *pre = NULL;
        int val = 0;
        while (cur || !s.empty()) {
            while (cur) {   
                s.push_back(cur);
                val += cur->val;
                cur = cur->left;
            }
            cur = s.back(); 
            if (!cur->left && !cur->right && val == sum) {
                vector<int> v;
                for (auto it : s) {
                    v.push_back(it->val);
                }
                res.push_back(v);
            }
            if (cur->right && cur->right != pre) cur = cur->right;
            else {
                pre = cur;
                val -= cur->val;
                s.pop_back();
                cur = NULL;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

