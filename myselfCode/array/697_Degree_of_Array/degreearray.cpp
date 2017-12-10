#include "../../leetcodeutil.h"

// class Solution {
// public:
//   int findShortestSubArray(vector<int>& nums) {
      
//   }
// };
// class Solution {
// public:
//     int findShortestSubArray(vector<int>& nums) {
//         if (nums.size() < 2) return nums.size();
//         // int res = nums.size();
//         unordered_map<int, int> startIndex, count;
//         int len = nums.size(), fre = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (startIndex.count(nums[i]) == 0) startIndex[nums[i]] = i;
//             count[nums[i]]++;
//             if (count[nums[i]] == fre){
//                 len = min(i - startIndex[nums[i]] + 1, len);
//             }
//             if (count[nums[i]] > fre){
//                 len = i - startIndex[nums[i]] + 1;
//                 fre = count[nums[i]];
//             }
//         }
//         return len;
//     }
// };
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int count[50000] = {0};      // number frequency
        int first[50000] = {0};      // number starting index
        int max_count = 0, last_max = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int curr_count = ++count[nums[i]];
            if (curr_count == 1) first[nums[i]] = i;    // record starting index
            if (curr_count > max_count) {               // find frequency max
                max_count = curr_count;
                last_max = i;
            } else if (curr_count == max_count) {       // equal frequency, compare interval
                if (last_max - first[nums[last_max]] > i - first[nums[i]]) {
                    last_max = i;
                }
            }
        }
        return last_max - first[nums[last_max]] + 1;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{1, 2, 2, 3, 1};
  vector<int> vect1{1,2,2,3,1,4,2};

  cout << Solution().findShortestSubArray(vect1) << endl;

  return 0;
}
