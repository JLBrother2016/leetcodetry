#include "leetcodeutil.h"

// class Solution {
// public:
//   vector<int> findDisappearedNumbers(vector<int>& nums) {
//     int len = nums.size();
//     sort(nums.begin(), nums.end());  
//     int maxnum = len;
//     vector<int> result;
//     int k = 0;
//     for(int i = 1; i <= maxnum; ++i){
//       if(nums[k] == i && nums[k] == nums[i]){
//         k += 2;
//       } else if(nums[k] == i) k++;
//       else  result.push_back(i);
//     }
//     return result;
//   } 
// };
/*class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
            cout << nums[m] << endl;
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i;
        for(i=0;i<nums.size(); i++)
        {
            while(nums[i]!=i+1 && nums[i]!= nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            cout << nums[i] <<endl;
        }
        vector<int> res;
        for(i=0;i<nums.size(); i++)
            if(nums[i]!=i+1)
                res.push_back(i+1);
        return res;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{4, 3, 2, 7, 8, 2, 3, 1}; 
  vector<int> vect1{1,1,2,4};

  cout << Solution().findDisappearedNumbers(vect) << endl;

  // cout << vector<vector<int>>(3, vector<int>{1, 2, 3}) << endl;

  return 0;
}

