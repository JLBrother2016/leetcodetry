#include "../leetcodeutil.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int len = nums.size();
      int zeronum = 0;

      for(int i = 0, j = 0; i < len; ++i) {
        if (nums[i] != 0) {
          nums[j++] = nums[i];
        } else zeronum++;
      } 

      for(int i = len - zeronum; i < len; ++i)
        nums[i] = 0; 
       // cout << nums << endl;
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         for (int i = 0, j = 0; i < nums.size(); i++) {
//             if (nums[i]) {
//                 if (i != j) {
//                     swap(nums[i], nums[j++]);    
//                 } else {
//                     j++;   
//                 }
//             }
//         }
//       // cout << nums << endl;  
//     }
// };

int main(int argc, char const *argv[])
{
  vector<int> vect{0, 1, 0, 3, 12}; 
  vector<int> vect1{4,2,4,0,0,3,0,5,1,0};

  Solution().moveZeroes(vect1);

  // cout << vector<vector<int>>(3, vector<int>{1, 2, 3}) << endl;

  return 0;
}

