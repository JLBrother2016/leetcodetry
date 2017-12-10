#include "../leetcodeutil.h"

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int len = nums.size();
//         // int result = 0;
//         for(int i = 0 ; i < len; ++i) {
//           if(target == nums[i])
//             return i;
//           else if (target < nums[i]) {
//              nums.insert(nums.begin() + i, target);
//             return i;
//           }
//         }
//         nums.insert(nums.begin() + len, target);
//         return len;
//     }
// };

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         if (nums.size() == 0) return 0;
//         int lo = 0;
//         int hi = nums.size() - 1;
//         while (lo < hi) {
//             int mid = (lo + hi) /2;
//             if (target == nums[mid]) return mid;
//             if (target < nums[mid]) {
//                 hi = mid - 1;
//             } else {
//                 lo = mid +1;
//             }
//         }
//         if (nums[lo] >= target) return lo;
//         else return lo + 1;
//     }
// };

class Solution {   //折半查找
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        if(target > nums.back()) return nums.size();
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target ) l = mid + 1;
            else r = mid;
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{1,3,5,6};
  vector<int> vect1{1};
  vector<int> vect2{2,4,1};

  cout << Solution().searchInsert(vect, 7) << endl;
  cout << vect << endl;

  return 0;
}