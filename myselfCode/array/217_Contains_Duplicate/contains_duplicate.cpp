#include "../leetcodeutil.h"

/*class Solution { //利用set
public:
  bool containsDuplicate(vector<int>& nums) {
    int len = nums.size();
    set<int> temp;
    for(int i = 0; i < len; ++i)
      temp.insert(nums[i]);

    return temp.size() < len ? true : false;
  }
};*/

// class Solution { //先排序
// public:
//   bool containsDuplicate(vector<int>& nums) {
//     int len = nums.size();
//     sort(nums.begin(), nums.end());
//     for(int i = 0; i < len - 1; ++i)
//       if(nums[i] == nums[i + 1])
//         return true;
//     return false;
//   }
// };

class Solution {  //unordered_set
public:
    // 10:42 Begin.
    // 10:42 (0 min) Got, algorithm.
    // 10:43 (1 min) 1st. AC!
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> data;
        for (auto cur : nums) {
            if (data.count(cur) != 0) return true;  //如果之前有插入元素
            data.insert(cur);
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
  

  return 0;
}
