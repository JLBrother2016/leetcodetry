#include "../leetcodeutil.h"

/*class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int left = 0;
        if(len < 1)
          return -1;
        for(int i = 0; i < len; ++i)
          sum += nums[i];

        // cout << sum << endl;
        for(int i = 0; i < len; ++i){
          if(i != 0) 
            left += nums[i - 1];

          // cout << left << endl;
          if(sum - left - nums[i] == left){
            // cout << i << endl;
            return i;
          }
        }
        return -1;
    }
};*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums) sum += x;
        int prev = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum -= nums[i];
            if(sum == prev) return i;
            prev += nums[i];
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{1, 7, 3, 6, 5, 6};
  vector<int> vect1{1, 2, 3};
  vector<int> vect2{2,4,1};

  cout << Solution().pivotIndex(vect) << endl;

  return 0;
}

