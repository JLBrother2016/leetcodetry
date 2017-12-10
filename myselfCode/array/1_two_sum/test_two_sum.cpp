#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int len = nums.size();
      vector<int> result;
        for(int i = 0; i < len; ++i){
          for(int j = i + 1; j < len; ++j){
            if (nums[i] + nums[j] == target){
              result.push_back(i);
              result.push_back(j);
              break;
            }
          }
        }
        return result;
    }
};

int main (int argc, char *argv[])
{
  int nums[3] = {3,2,4};
  int target = 6;
  vector<int> vnums;
  for(int i = 0; i < 3; ++i){
    vnums.push_back(nums[i]);
  }
  class Solution s;
  vector<int> re = s.twoSum(vnums, target);

  for(int i = 0; i < 2; ++i)
    cout << re[i] << endl;

  return 0;
}
