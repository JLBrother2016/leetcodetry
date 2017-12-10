#include "../leetcodeutil.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int result = 1;
        int temp = 1;
        if(len < 1)
            return 0;
        for(int i = 0; i < len - 1; ++i){
            if(nums[i] < nums[i + 1])
                temp++;
            else temp = 1;
            if (temp > result)
              result = temp;
        }
        return result;   
    }
};

/*class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] > nums[i-1])
                res = max(res, ++count);
            else
                count = 1;
        }
        return res;
    }
};*/

int main(int argc, char const *argv[])
{
  vector<int> vect{1,3,5,4,7};
  vector<int> vect1{2,2,2,2,2};

  cout << Solution().findLengthOfLCIS(vect1) << endl;

  return 0;
}