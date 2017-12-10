#include "../leetcodeutil.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int begi = -1, end = -2;
        int minnum = nums[n -1], maxnum = nums[0];
        for(int i = 0; i < n; ++i) {
          maxnum = max(maxnum, nums[i]);
          minnum = min(minnum, nums[n - 1 - i]);
          if (nums[i] < maxnum)
            end = i;
          if (nums[n - 1 - i] > minnum)
            begi = n - 1 - i;
        }

        return end - begi + 1;
    }
};

// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         const int N = (int)nums.size();
//         // 先从两端向内找到第一个无序的位置
//         int i = 0, j = N - 1;
//         while (i < N - 1 && nums[i] <= nums[i + 1])
//             i++;
//         while (j > 0 && nums[j - 1] <= nums[j])
//             j--;
//         if (i >= j) return 0;
//         // 在nums[i..j]中找到minNum和maxNum
//         int minNum = INT_MAX, maxNum = INT_MIN;
//         for (int k = i; k <= j; k++) {
//             minNum = min(minNum, nums[k]);
//             maxNum = max(maxNum, nums[k]);
//         }
//         // 根据nums[i-1]<=minNum、nums[j+1]>=maxNum向外扩展
//         while (i >= 1 && nums[i - 1] > minNum)
//             i--;
//         while (j < N - 1 && nums[j + 1] < maxNum)
//             j++;
        
//         return j - i + 1;
//     }
// };

int main(int argc, char const *argv[])
{
  vector<int> vect{2, 6, 4, 8, 10, 9, 15};

  cout << Solution().findUnsortedSubarray(vect) << endl;
  cout << vect << endl;


  return 0;
}
