#include "../leetcodeutil.h"

class Solution {
public:
	// 采用回溯法实现, 回溯算法的基本形式是“递归+循环”
	// 原数组中的每个元素有两种状态：存在和不存在
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) {
        	return {};
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        subsets(nums, ans, tmp, 0);

        return ans;
    }
private:
	void subsets(vector<int>& nums, vector<vector<int>>& ans, 
				 vector<int>& temp, int index) {
		ans.push_back(temp);
		for(int i = index; i < nums.size(); ++i) {
			temp.push_back(nums[i]);
			subsets(nums, ans, temp, i+1);
			temp.pop_back();
		}
	}
};

class Solution {
public:
    void buildSols(const vector<int>& nums, int pos, vector<int>& currentSol, vector<vector<int> >& sols) {
        if (pos == nums.size()) {    //访问到了数组末尾
            sols.push_back(currentSol);
            return ;
        }  //这种方法会快很多, 一直递归到数组结尾
        buildSols(nums, pos + 1, currentSol, sols); // 递归里面再递归(两次递归)
        currentSol.push_back(nums[pos]);			// 这个有点复杂
        buildSols(nums, pos + 1, currentSol, sols); //pos等与size()-1时会直接返回
        currentSol.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > sols;
        vector<int> currentSol;
        buildSols(nums, 0, currentSol, sols);
        return sols;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> iv{1, 2, 3};
	cout << Solution().subsets(iv) << endl;
	

	return 0;
}
