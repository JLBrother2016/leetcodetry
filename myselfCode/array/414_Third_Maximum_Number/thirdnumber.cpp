#include "../leetcodeutil.h"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        if(len == 2)
          return max(nums[0], nums[1]);
        else if(len == 1)
          return nums[0];
        set<int> top3;
        for(int i = 0; i < len; ++i) {
          top3.insert(nums[i]);
          if(top3.size() > 3)
            top3.erase(top3.begin());
        }
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;
        for (const int& num : nums) {
            top3.insert(num);
            if (top3.size() > 3) {
                top3.erase(top3.begin());
            }
        }
        return top3.size() == 3 ? *(top3.begin()) : *(top3.rbegin());
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{2, 2, 3, 1};
  vector<int> vect1{2, 1};
  cout << Solution().thirdMax(vect1) << endl;

  return 0;
}

