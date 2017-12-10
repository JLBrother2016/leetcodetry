#include "../leetcodeutil.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i = !nums.empty();
       for(int n : nums)
        if(n > nums[i - 1])
          nums[i++] = n;
       return i;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect1{1, 1, 2, 2};

  cout << Solution().removeDuplicates(vect1) << endl;

  cout << vect1 << endl;

  return 0;
}

