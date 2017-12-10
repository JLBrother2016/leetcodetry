#include "../leetcodeutil.h"

// class Solution 
// {
// public:
//     void rotate(vector<int> &nums, int k) 
//     {
//       int n = nums.size();
//         if ((n == 0) || (k <= 0))
//         {
//             return;
//         }
        
//         // Make a copy of nums
//         vector<int> numsCopy(n);
//         for (int i = 0; i < n; i++)
//         {
//             numsCopy[i] = nums[i];
//         }
        
//         // Rotate the elements.
//         for (int i = 0; i < n; i++)
//         {
//             nums[(i + k)%n] = numsCopy[i];
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n | k == 0) return;
        k %= n;
        reverse(nums.begin(), nums.begin() + n - k) ;
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect1{1,2,3,4,5,6,7};
  Solution().rotate(vect1, 3); 
  cout << vect1 << endl;

  return 0;
}
