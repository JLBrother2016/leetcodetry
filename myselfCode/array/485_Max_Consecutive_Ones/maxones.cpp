#include "leetcodeutil.h"
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int result = 0;
      int len = nums.size();
      int tmp = 0;

      for(int i = 0; i < len; ++i){
        if(nums[i] == 0)
          tmp = 0;
        else tmp++;
        if(result < tmp)
          result = tmp;
      } 
      return result;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vct{1, 1, 0, 1, 1, 1};
  cout << Solution().findMaxConsecutiveOnes(vct) << endl; 

  return 0;
}