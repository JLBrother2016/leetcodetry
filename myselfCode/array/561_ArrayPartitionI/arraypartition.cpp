// #include <iostream>
#include "leetcodeutil.h"

// using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      // cout << nums << endl;
      sort (nums.begin(), nums.end());
      // cout << nums << endl;
      int len = nums.size();
      int sum = 0;
      for(int i = 0; i < len/2; ++i){
        // if(i % 2 == 0)
          sum += nums[i*2];
      }

      return sum;
    }
};

int main(int argc, char const *argv[])
{
  int start = TimeUtil::getCurrentTimeMs();

  std::vector<int> vct{1, 4, 2, 3};
  for(int i = 0; i < 100000; i++)
    Solution().arrayPairSum(vct);
  cout << Solution().arrayPairSum(vct) << endl;

  int end = TimeUtil::getCurrentTimeMs();

  cout << (end - start) << endl;

  return 0;
}

