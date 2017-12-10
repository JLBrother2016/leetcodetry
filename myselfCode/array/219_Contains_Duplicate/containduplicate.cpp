#include "../leetcodeutil.h"

// class Solution {  //又做错了
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int len = nums.size();
//         for(int i = 0; i < len; ++i) {
//           for(int j = i + 1; j <= min(i + k, len); ++j) {
//             // cout << j << endl;
//             if(nums[i] == nums[j]) 
//               return true;
//           }
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;
       
       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;
       
       for (int i = 0; i < nums.size(); i++)  //窗移+查找
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};

/*class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& ns, int k) {
        int n = ns.size();
        vector<pair<int, int>> ps(n);
        for (int i = 0; i < n; i++) {
            ps[i].first = ns[i];
            ps[i].second = i;
        }
        
        sort(ps.begin(), ps.end());
        
        for (int i = 1; i < n; i++) {
            if (ps[i].first == ps[i - 1].first
                && abs(ps[i].second - ps[i - 1].second) <= k) {
                return true;
            } 
        }
        
        return false;
    }
};*/


int main(int argc, char const *argv[])
{
  vector<int> vect1{0,1,2,3,4,5,0};
  vector<int> vect{-1, -1};


  cout << Solution().containsNearbyDuplicate(vect1, 5) << endl;

  return 0;
}
