#include "../leetcodeutil.h"

/*class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int result = nums[0];
    int num = 0, temp = 0;
    for(int i = 0; i < len - 1; ++i){
      if(nums[i] == nums[i+1]){
        num ++;
      } else {
        num = 0;
      }
      if (num > temp){
        result = nums[i];
        temp = num;
      }
    }
    return result;
  }
};*/

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int key = 0, count = 0;
        
        for (auto num : nums) {
            if (count == 0) {
                key = num;
                count++;
            } else if (key == num) {
                count++;
            } else {
                count--;
            }
        }
        return key;
    }
};*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {  //最后cnt始终大于0
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {res = num; ++cnt;}
            else (num == res) ? ++cnt : --cnt;
        }
        return res;
    }
};



int main(int argc, char const *argv[])
{
  

  return 0;
}
