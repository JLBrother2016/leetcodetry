#include "leetcodeutil.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
      int row = nums.size();
      int column = nums[0].size();
      if((row * column) != (r * c))
        return nums;
      vector<int> temp;
      vector<vector<int>> result(r);
      for (int i = 0; i < result.size(); i++)
        result[i].resize(c);

      for(int i = 0; i < row; ++i)
        for(int j = 0; j < column; ++j)
          temp.push_back(nums[i][j]);
      int k = 0;
      for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j) {
          result[i][j] = temp[k++]; 
        }
      }
      return result;
    }
};


int main(int argc, char const *argv[])
{
  vector<vector<int>> vct{ {1, 2}, {3, 4}};
  for(int i = 0; i < vct.size(); ++i)
    for(int j = 0; j < vct[0].size(); ++j)
      cout << vct[i][j] << endl;

  vector<vector<int>> re = Solution().matrixReshape(vct, 2, 4);

  for(int i = 0; i < re.size(); i++){
    for(int j = 0; j < re[0].size(); j++)
      cout << re[i][j] << ' ';
    cout << endl;
  }
  // cout << x << endl;
  
  return 0;
}
