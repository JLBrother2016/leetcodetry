#include "../leetcodeutil.h"
// class Solution {
// public:
//     /**
//      * for every number in the array:
//      *  - if there was a number previously k-diff with it, save the smaller to a set;
//      *  - and save the value-index to a map;
//      */
//     int findPairs(vector<int>& nums, int k) {
//         if (k < 0) {
//             return 0;
//         }
//         unordered_set<int> starters;
//         unordered_map<int, int> indices;
//         for (int i = 0; i < nums.size(); i++) {
//             if (indices.count(nums[i] - k)) {
//                 starters.insert(nums[i] - k);
//             }
//             if (indices.count(nums[i] + k)) {
//                 starters.insert(nums[i]);
//             }

//             indices[nums[i]] += 1;
//         }
        
//         return starters.size();
//     }
// };

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        if(nums.size() <= 1) return 0;

        map<int, int> m;
        for(int i: nums) m[i] += 1;

        int result = 0;
        for(auto it = m.begin(); it != m.end(); ++it) {
          cout << it->first << endl;
            // if(k != 0)
            // {
            //     if(m.find(it->first + k) != m.end())
            //         ++result;
            // } else {
            //     if(m[it->first] >= 2)
            //         ++result;
            // }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{3, 1, 4, 1, 5};
  cout << Solution().findPairs(vect, 2) << endl;

  return 0;
}
