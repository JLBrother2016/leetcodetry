#include "../leetcodeutil.h"
// class Solution { //这个方法比较浪费空间
// public:
//   int missingNumber(vector<int>& nums) {
//     int len = nums.size();
//     vector<int> hash(len + 1);
//     for(int i = 0; i < len; ++i){
//       hash[nums[i]] = -1;
//     } 
//     for(int i = 0; i < len +1; ++i){
//       if(hash[i] != -1)
//         return i;
//     }
//     return 0;
//   }
// };
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int sum = 0;
    for (auto v : nums)
      sum +=v;
    int size = nums.size();
    size = (size)*(size+1)/2;    //连续数列的求和，这种方法很好
    return (size - sum);
  }
};

/*
@problem:Missing Number
@author:Carlos
@time complexity: O(n)
@space complexity: O(1)
@main idea: (0+1+2+...+n) - sum(nums[i] for all i) = the missing number
*/

/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            while(nums[i]>=0&&nums[i]<n&&i!=nums[i])
                swap(nums[i],nums[nums[i]]);
        for(int i=0;i<n;i++)
            if(nums[i]!=i)
                return i;
        return n;
    }  
};*/

int main(int argc, char const *argv[])
{
  vector<int> vect{3,0,1};
  vector<int> vect1{9,6,4,2,3,5,7,0,1};
  // vector<int> vect2{1,0,100};

  cout << Solution().missingNumber(vect1) << endl;

  return 0;
}